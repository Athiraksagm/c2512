#include "httplib.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <atomic>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <array>
#include <memory>

using json = nlohmann::json;

std::atomic<int> boot_count(0);
std::atomic<long> total_uptime(0);

// Function to get the system's boot count from `last reboot`
int getBootCount()
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen("last reboot | wc -l", "r"), pclose);
    if (!pipe) {
        std::cerr << "Failed to run command." << std::endl;
        return -1;
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return std::stoi(result);  // Convert output to integer
}

// Function to get the system's boot time as a Unix timestamp
long getSystemBootTime() 
{
    std::ifstream stat_file("/proc/stat");
    std::string line;
    
    if (stat_file.is_open()) {
    
        std::getline(stat_file, line);
        std::istringstream ss(line);
        std::string label;
        long boot_time = 0;

        if (ss >> label >> boot_time) {
            return boot_time; 
        }
    }
    std::cerr << "Error reading system boot time from /proc/stat!" << std::endl;
    return 0;
}

// Load the last boot time from the file
long loadLastBootTime() 
{
    std::ifstream file("../last_boot_time.txt");
    long last_boot_time = 0;
    if (file.is_open()) {
        file >> last_boot_time;
        file.close();
    }
    return last_boot_time;
}

// Save the current boot time to the file as a Unix timestamp
void saveLastBootTime(long boot_time) 
{
    std::ofstream file("../last_boot_time.txt");
    if (file.is_open()) {
        file << boot_time;
        file.close();
    }
}

// Save system stats to CSV
void saveStatsToCSV() 
{
    std::ofstream file("../system_stats.csv", std::ios_base::app);
    if (file.is_open()) {
        std::time_t now = std::time(nullptr);
        std::tm *local_time = std::localtime(&now);

        // Append stats to CSV: Date, Time, Boot Count, Uptime (seconds)
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
}

// Update the system uptime
void updateUptime() 
{
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        total_uptime.store(info.uptime);  // Store uptime in atomic variable
    }
}

// Handle the client request to fetch stats
void handleClientRequest(const httplib::Request &req, httplib::Response &res) 
{
    updateUptime();  

    json response_json;
    response_json["boot_count"] = boot_count.load();
    response_json["uptime"] = total_uptime.load();

    saveStatsToCSV(); 

    std::cout << "[Request Received] Boot Count: " << boot_count.load() << ", Uptime: " << total_uptime.load() << " seconds\n";

    res.set_header("Cache-Control", "no-store");
    res.set_content(response_json.dump(), "application/json");
}

int main() 
{
    // Load the boot count from the system
    boot_count.store(getBootCount());

    std::cout << "=============================\n"
              << " SYSTEM STAT LOGGING SERVER\n"
              << "=============================\n";

    std::cout << "Boot Count: " << boot_count.load() << "\n";
    std::cout << "Server running at http://localhost:8080...\n";
    std::cout << "Waiting for client requests...\n";

    // Ensure system_stats.csv file exists and has headers if it's the first run
    std::ifstream checkFile("../system_stats.csv");
    if (!checkFile.is_open()) {
        std::ofstream file("../system_stats.csv");
        if (file.is_open()) {
            file << "Date (YYYY-MM-DD), Time (HH:MM:SS), Boot Count, Uptime (seconds)\n";
            file.close();
        }
    }
    checkFile.close();

    // Start the server and listen for requests
    httplib::Server server;
    server.Get("/stats", handleClientRequest);
    server.listen("localhost", 8080);

    return 0;
}
