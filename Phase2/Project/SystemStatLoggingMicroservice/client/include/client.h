#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <csignal>
#include <atomic>
#include <memory>
#include <csignal>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <nlohmann/json.hpp>
#include "httplib.h"

class SystemStatClient 
{
public:
    SystemStatClient(const std::string& server_ip, int rest_port, int ws_port, bool log_to_file);
    ~SystemStatClient();

    void requestInitialStats();
    void connectToWebSocket();
    void signalHandler(int signum);
    
    static void globalSignalHandler(int signum);

private:
    void saveStatsToCSV(int boot_count, long uptime);
    
    std::string host;
    int restPort;
    int wsPort;
    bool logToFile;
    
    std::shared_ptr<boost::beast::websocket::stream<boost::asio::ip::tcp::socket>> wsClient;
    std::atomic<bool> stopClient;
};

#endif
