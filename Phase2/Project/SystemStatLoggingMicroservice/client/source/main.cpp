#include "client.h"

int main(int argc, char* argv[]) 
{
    std::string host = "0.0.0.0";
    int rest_port = 8080;
    int ws_port = 9000;
    bool logToFile = false;

    if (argc > 1) {
        std::string input_host = argv[1];
        if (input_host != host) {
            std::cerr << "Error: Client must use the same IP as the server (" << host << ").\n";
            return 1;
        }
        host = input_host;
    }

    if (argc > 2) {
        try {
            rest_port = std::stoi(argv[2]);
            ws_port = std::stoi(argv[3]);
        } catch (...) {
            std::cerr << "Error: Invalid port numbers. Using default ports (REST: 8080, WS: 9000).\n";
            rest_port = 8080;
            ws_port = 9000;
        }
    }

    if (argc > 4 && std::string(argv[4]) == "--log") {
        logToFile = true;
    }

    std::cout << "=============================\n"
              << " SYSTEM STAT LOGGING CLIENT\n"
              << "=============================\n\n";

    SystemStatClient client(host, rest_port, ws_port, logToFile);

    std::signal(SIGINT, SystemStatClient::globalSignalHandler);
    std::cout << "Requesting initial stats from " << host << ":" << rest_port << "\n";
    client.requestInitialStats();

    std::cout << "\nConnecting to WebSocket at " << host << ":" << ws_port << " for periodic updates...\n";
    client.connectToWebSocket();

    return 0;
}
