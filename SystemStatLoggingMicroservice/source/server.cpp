#include "httplib.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <atomic>
#include <sys/sysinfo.h>
#include <unistd.h>

using json = nlohmann::json;

std::atomic<int> boot_count(0);
std::atomic<long> total_uptime(0);

long getSystemBootTime() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        return time(nullptr) - info.uptime;
    }
    return 0;
}

int loadBootCount() {
    std::ifstream file("boot_count.txt");
    int count = 0;
    if (file.is_open()) {
        file >> count;
        file.close();
    }
    return count;
}

void saveBootCount(int count) {
    std::ofstream file("boot_count.txt");
    if (file.is_open()) {
        file << count;
        file.close();
    }
}

bool hasSystemRebooted() {
    long current_boot_time = getSystemBootTime();
    std::ifstream file("last_boot_time.txt");
    long last_boot_time = 0;

    if (file.is_open()) {
        file >> last_boot_time;
        file.close();
    } else {
        std::ofstream saveFile("last_boot_time.txt");
        if (saveFile.is_open()) {
            saveFile << current_boot_time;
            saveFile.close();
        }
        return false;
    }

    if (current_boot_time > 0 && current_boot_time != last_boot_time) {
        std::ofstream saveFile("last_boot_time.txt");
        if (saveFile.is_open()) {
            saveFile << current_boot_time;
            saveFile.close();
        }
        return true;
    }

    return false;
}

void saveStatsToCSV() 
{
    std::ofstream file;
    file.open("system_stats.csv", std::ios_base::app); 

    if (file.is_open()) {

    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);
    
    file << 1900 + local_time->tm_year << "-"
         << 1 + local_time->tm_mon << "-"
         << local_time->tm_mday << ", "
         << local_time->tm_hour << ":"
         << local_time->tm_min << ":"
         << local_time->tm_sec << ", "
         << boot_count.load() << ", "  
          << total_uptime.load() << "\n";
    } else {
        std::cerr << "Error opening CSV file!" << std::endl;
    }
    file.close();
}

void updateUptime() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        total_uptime.store(info.uptime);
    }
}

void handleClientRequest(const httplib::Request &req, httplib::Response &res) {
    updateUptime();

    json response_json;
    response_json["boot_count"] = boot_count.load();
    response_json["uptime"] = total_uptime.load();

    saveStatsToCSV(); 

    std::cout <<  "[Request Received] Boot Count: " << boot_count.load() << ", Uptime: " << total_uptime.load() << " seconds\n";

    res.set_header("Cache-Control", "no-store");
    res.set_content(response_json.dump(), "application/json");
}

int main() {
    int stored_boot_count = loadBootCount();

    if (hasSystemRebooted()) {
        stored_boot_count += 1;
        saveBootCount(stored_boot_count);
    }

    boot_count.store(stored_boot_count);

    std::cout << "=============================\n" << " SYSTEM STAT LOGGING SERVER\n" << "=============================\n";

    std::cout << "Boot Count: " << boot_count.load() << "\n";
    std::cout << "Server running at http://localhost:8080...\n";
    std::cout << "Waiting for client requests...\n";

    std::ifstream checkFile("system_stats.csv");
    if (!checkFile.is_open()) {
        std::ofstream file("system_stats.csv");
        if (file.is_open()) {
            file << " Date (YYYY-MM-DD), Time (HH-MM-SS), Boot Count, Uptime (seconds)" << std::endl;  
            file.close();
        }
    }
    checkFile.close();

    httplib::Server server;
    server.Get("/stats", handleClientRequest);
    server.listen("localhost", 8080);

    return 0;
}
