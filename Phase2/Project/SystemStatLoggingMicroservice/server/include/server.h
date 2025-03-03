#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/websocket.hpp>
#include "json.hpp"
#include "httplib.h"
#include "tinyxml2.h"
#include <iostream>
#include <unordered_set>
#include <mutex>
#include <thread>
#include <sys/sysinfo.h>
#include <atomic>

using namespace boost::asio;
using namespace boost::beast;
using json = nlohmann::json;
using namespace tinyxml2;

const int DEFAULT_LOGGING_INTERVAL = 10;
const std::string CONFIG_FILE_PATH = "../source/config.xml";

class Server {
protected:
    std::atomic<int> boot_count;
    std::unordered_set<std::shared_ptr<websocket::stream<ip::tcp::socket>>> clients;
    std::mutex clients_mutex;
    int logging_interval = DEFAULT_LOGGING_INTERVAL;
    io_context ioc;
    long getUptime();
    int getBootCount();
    
public:
    Server();
    void loadConfig();
    void broadcastStats();
    void handleWebSocketClient(ip::tcp::socket socket);
    void startRESTServer(int restPort);
    void startWebSocketServer(int wsPort);
    void sendPeriodicStats();

    int getBootCountValue() {
        return getBootCount();
    }
    long getUptimeValue() {
        return getUptime();
    }
    int getLoggingInterval(){
        return logging_interval;
    }
};

#endif
