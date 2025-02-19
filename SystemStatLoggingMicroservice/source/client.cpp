#include <iostream>
#include <httplib.h>
#include <json.hpp>
#include <thread>
#include <chrono>

using json = nlohmann::json;

//Function to continuously request system statistics from the server
void requestStats() 
{
    httplib::Client client("http://localhost:8080");

    while (true) {
        auto res = client.Get("/stats");

        if (res && res->status == 200) {
            json stats = json::parse(res->body);

            std::cout << "Received stats:\n";
            std::cout << "Boot Count: " << stats["boot_count"] << "\n";
            std::cout << "Uptime: " << stats["uptime"] << " seconds\n";
        } else {
            std::cerr << "Failed to get stats from server.\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

//Main function to initialize the client and start requesting stats 
int main() 
{
    std::cout << "=============================\n" << " SYSTEM STAT LOGGING CLIENT\n" << "=============================\n";
    std::cout << "Client is requesting stats from server...\n";
    requestStats();
    return 0;
}
