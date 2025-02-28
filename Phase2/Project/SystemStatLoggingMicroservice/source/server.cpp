// #include "server.h"
// //#include "../include/server.h"

// Server::Server() : boot_count(0), logging_interval(10) {
//     loadConfig();
//     boot_count.store(getBootCount());
// }

// /**
//  * @brief Loads configuration settings from `config.xml`.
//  * 
//  * This function reads the logging interval from the XML configuration file.
//  * If the file is missing or contains invalid data, it falls back to the default interval.
//  */
// void Server::loadConfig() {
//             XMLDocument doc;
//             if (doc.LoadFile("../source/config.xml") != XML_SUCCESS) {
//                 std::cerr << "Error: Could not load config.xml. Using default logging interval.\n";
//                 return;
//             }
//             XMLElement *root = doc.FirstChildElement("config");
//             if (!root) {
//                 std::cerr << "Error: <config> element missing in config.xml. Using default.\n";
//                 return;
//             }
//             XMLElement *interval_element = root->FirstChildElement("logging_interval");
//             if (!interval_element) {
//                 std::cerr << "Error: <logging_interval> element missing in config.xml. Using default.\n";
//                 return;
//             }
//             const char* interval_text = interval_element->GetText();
//             if (interval_text && std::all_of(interval_text, interval_text + strlen(interval_text), ::isdigit)) {
//                 try {
//                     logging_interval = std::stoi(interval_text);
//                     std::cerr << "Logging interval set to: " << logging_interval << "s\n";
//                 } catch (...) {
//                     std::cerr << "Error: Invalid logging interval in config.xml. Using default.\n";
//                     logging_interval = DEFAULT_LOGGING_INTERVAL;
//                 }
//             } else {
//                 std::cerr << "Error: Invalid logging interval in config.xml. Using default.\n";
//                 logging_interval = DEFAULT_LOGGING_INTERVAL;
//             }
// }

// /**
//  * @brief Retrieves the system boot count.
//  * 
//  * @return The number of times the system has booted. Returns -1 on failure.
//  */
// int Server::getBootCount() {
//             FILE *pipe = popen("last reboot | wc -l", "r");
//             if (!pipe) {
//                 std::cerr << "Error: Failed to execute system command for boot count.\n";
//                 return -1;
//             }
//             char buffer[128];
//             if (!fgets(buffer, sizeof(buffer), pipe)) {
//                 std::cerr << "Error: Failed to read boot count from command output.\n";
//                 pclose(pipe);
//                 return -1;
//             }
//             pclose(pipe);
//             try {
//                 int count = std::stoi(buffer);
//                 return (count > 0) ? count : -1;
//             } catch (...) {
//                 std::cerr << "Error: Invalid boot count format.\n";
//                 return -1;
//             }
//         }

// /**
//  * @brief Retrieves the system uptime.
//  * 
//  * @return The system uptime in seconds. Returns -1 on failure.
//  */
// long Server::getUptime() {
//     struct sysinfo info;
//     if (sysinfo(&info) != 0) {
//         std::cerr << "Error: Failed to retrieve system uptime.\n";
//         return -1;
//     }
//     return info.uptime;
// }

// /**
//  * @brief Broadcasts system statistics to all connected WebSocket clients periodically.
//  * 
//  * This function runs in a loop, sending boot count and uptime at the configured interval.
//  */
// void Server::broadcastStats() {
//     while (true) {
//         json stats;
//         stats["boot_count"] = boot_count.load();
//         stats["uptime"] = getUptime();
//         std::string message = stats.dump();

//         std::vector<std::shared_ptr<websocket::stream<ip::tcp::socket>>> disconnected_clients;

//         {
//             std::lock_guard<std::mutex> lock(clients_mutex);
//             for (auto &client : clients) {
//                 boost::system::error_code ec;
//                 client->write(net::buffer(message), ec);
//                 if (ec) disconnected_clients.push_back(client);
//             }
//             for (const auto &client : disconnected_clients) {
//                 clients.erase(client);
//             }
//         }

//         std::this_thread::sleep_for(std::chrono::seconds(logging_interval));
//     }
// }

// /**
//  * @brief Starts the REST API server to provide system statistics on request.
//  * 
//  * @param restPort The port number on which the REST API server listens.
//  */
// void Server::startRESTServer(int restPort) {
//     httplib::Server server;

//     server.Get("/fetchSystemStats", [this](const httplib::Request &, httplib::Response &res) {
//         json response;
//         response["boot_count"] = boot_count.load();
//         response["uptime"] = getUptime();
//         res.set_content(response.dump(), "application/json");
//     });

//     std::cout << "REST API Server running on port " << restPort << "\n";
//     server.listen("0.0.0.0", restPort);
// }

// /**
//  * @brief Handles an incoming WebSocket client connection.
//  * 
//  * @param socket The connected socket for the WebSocket client.
//  */
// void Server::handleWebSocketClient(ip::tcp::socket socket) {
//     try {
//         auto ws = std::make_shared<websocket::stream<ip::tcp::socket>>(std::move(socket));
//         ws->accept();

//         {
//             std::lock_guard<std::mutex> lock(clients_mutex);
//             clients.insert(ws);
//         }

//         boost::beast::flat_buffer buffer;
//         boost::system::error_code ec;

//         while (ws->is_open()) {
//             ws->read(buffer, ec);
//             if (ec == websocket::error::closed) break;
//             if (ec) {
//                 std::cerr << "WebSocket client error: " << ec.message() <<"\n";
//                 break;
//             }
//         }

//         {
//             std::lock_guard<std::mutex> lock(clients_mutex);
//             clients.erase(ws);
//         }

//     } catch (const std::exception &e) {
//         std::cerr << "WebSocket client error: " << e.what() << "\n";
//     }
// }

// /**
//  * @brief Starts the WebSocket server to handle client connections for periodic stats updates.
//  * 
//  * @param wsPort The port number on which the WebSocket server listens.
//  */
// void Server::startWebSocketServer(int wsPort) {
//     ip::tcp::acceptor acceptor(ioc, ip::tcp::endpoint(ip::tcp::v4(), wsPort));
//     std::cout << "WebSocket Server running on port " << wsPort << "\n";

//     while (true) {
//         ip::tcp::socket socket(ioc);
//         acceptor.accept(socket);
//         std::thread(&Server::handleWebSocketClient, this, std::move(socket)).detach();
//     }
// }

// /**
//  * @brief Sends periodic system statistics updates to all connected WebSocket clients.
//  * 
//  * This function runs continuously, sending system stats every few seconds.
//  */
// void Server::sendPeriodicStats() {
//     while (true) {
//         std::this_thread::sleep_for(std::chrono::seconds(10));
//         json periodicStats;
//         periodicStats["boot_count"] = boot_count.load();
//         periodicStats["uptime"] = getUptime();

//         std::lock_guard<std::mutex> lock(clients_mutex);
//         for (auto &client : clients) {
//             boost::system::error_code ec;
//             client->write(net::buffer(periodicStats.dump()), ec);
//             if (ec) {
//                  std::cerr << "Error sending periodic stats: " << ec.message() << "\n";
//             }
//         }
//     }
// }




//#include "server.h"
#include "../include/server.h"

Server::Server() : boot_count(0), logging_interval(10) {
    loadConfig();
    boot_count.store(getBootCount());
}

void Server::loadConfig() {
    XMLDocument doc;
    if (doc.LoadFile("../source/config.xml") != XML_SUCCESS) {
        std::cerr << "Error: Could not load config.xml. Using default logging interval.\n";
        logging_interval = 10; // Default
        return;
    }
    XMLElement *root = doc.FirstChildElement("config");
    if (!root) {
        std::cerr << "Error: Missing <config> in config.xml. Using default.\n";
        return;
    }
    XMLElement *interval_element = root->FirstChildElement("logging_interval");
    if (!interval_element) {
        std::cerr << "Error: <logging_interval> missing in config.xml. Using default.\n";
        return;
    }
    const char *interval_text = interval_element->GetText();
    if (interval_text && std::all_of(interval_text, interval_text + strlen(interval_text), ::isdigit)) {
        try {
            logging_interval = std::stoi(interval_text);
            std::cerr << "Logging interval set to: " << logging_interval << "s\n";
        } catch (...) {
            std::cerr << "Error: Invalid logging interval in config.xml. Using default.\n";
            logging_interval = 10;
        }
    } else {
        std::cerr << "Error: Invalid logging interval format. Using default.\n";
        logging_interval = 10;
    }
}

int Server::getBootCount() {
    FILE *pipe = popen("last reboot | wc -l", "r");
    if (!pipe) {
        std::cerr << "Error: Failed to execute boot count command.\n";
        return -1;
    }
    char buffer[128];
    if (!fgets(buffer, sizeof(buffer), pipe)) {
        std::cerr << "Error: Failed to read boot count.\n";
        pclose(pipe);
        return -1;
    }
    pclose(pipe);
    try {
        int count = std::stoi(buffer);
        return (count > 0) ? count : -1;
    } catch (...) {
        std::cerr << "Error: Invalid boot count format.\n";
        return -1;
    }
}

long Server::getUptime() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        std::cerr << "Error: Failed to retrieve system uptime.\n";
        return -1;
    }
    return info.uptime;
}

void Server::broadcastStats() {
    json stats;
    stats["boot_count"] = boot_count.load();
    stats["uptime"] = getUptime();
    std::string message = stats.dump();

    std::vector<std::shared_ptr<websocket::stream<ip::tcp::socket>>> disconnected_clients;

    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        for (auto &client : clients) {
            boost::system::error_code ec;
            client->write(net::buffer(message), ec);
            if (ec) disconnected_clients.push_back(client);
        }
        for (const auto &client : disconnected_clients) {
            clients.erase(client);
        }
    }
}

void Server::sendPeriodicStats() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(logging_interval));
        broadcastStats();
    }
}

void Server::startRESTServer(int restPort) {
    httplib::Server server;
    server.Get("/fetchSystemStats", [this](const httplib::Request &, httplib::Response &res) {
        json response;
        response["boot_count"] = boot_count.load();
        response["uptime"] = getUptime();
        res.set_content(response.dump(), "application/json");
    });

    std::cout << "REST API Server running on port " << restPort << "\n";
    server.listen("0.0.0.0", restPort);
}

void Server::startWebSocketServer(int wsPort) {
    ip::tcp::acceptor acceptor(ioc, ip::tcp::endpoint(ip::tcp::v4(), wsPort));
    std::cout << "WebSocket Server running on port " << wsPort << "\n";

    while (true) {
        ip::tcp::socket socket(ioc);
        acceptor.accept(socket);
        std::thread(&Server::handleWebSocketClient, this, std::move(socket)).detach();
    }
}

void Server::handleWebSocketClient(ip::tcp::socket socket) {
    try {
        auto ws = std::make_shared<websocket::stream<ip::tcp::socket>>(std::move(socket));
        ws->accept();

        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.insert(ws);
        }

        boost::beast::flat_buffer buffer;
        boost::system::error_code ec;
        while (ws->is_open()) {
            ws->read(buffer, ec);
            if (ec == websocket::error::closed) break;
        }

        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.erase(ws);
        }
    } catch (const std::exception &e) {
        std::cerr << "WebSocket client error: " << e.what() << "\n";
    }
}

