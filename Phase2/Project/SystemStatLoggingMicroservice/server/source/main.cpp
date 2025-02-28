#include "server.h"

int main(int argc, char* argv[]) {
    std::cout << "=============================\n"
              << " SYSTEM STAT LOGGING SERVER\n"
              << "=============================\n\n";
    const std::string ip_address = "0.0.0.0";
    int rest_port = 8080;
    int ws_port = 9000;

    if (argc > 2) {
        try {
            rest_port = std::stoi(argv[1]);
            ws_port = std::stoi(argv[2]);
            if (rest_port <= 0 || rest_port > 65535 || ws_port <= 0 || ws_port > 65535) {
                throw std::out_of_range("Invalid port range");
            }
        } catch (...) {
            std::cerr << "Error: Invalid port arguments. Using default ports (REST: 8080, WS: 9000).\n";
            rest_port = 8080;
            ws_port = 9000;
        }
    }
    
    std::cout << "REST API Server running at http://" << ip_address << ":" << rest_port << "\n";
    std::cout << "WebSocket Server running at ws://" << ip_address << ":" << ws_port << "\n\n";

    Server server;
    std::thread rest_thread(&Server::startRESTServer, &server, rest_port);
    std::thread ws_thread(&Server::startWebSocketServer, &server, ws_port);

    rest_thread.detach();
    ws_thread.detach();

    server.sendPeriodicStats();
    return 0;
}
