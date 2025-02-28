#include "client.h"

using namespace boost::asio;
using namespace boost::beast;
using json = nlohmann::json;

const std::string CSV_FILE_PATH = "../source/system_stats.csv";
namespace websocket = boost::beast::websocket;

SystemStatClient* globalClientInstance = nullptr;

/**
 * @brief Constructs the SystemStatClient object.
 */
SystemStatClient::SystemStatClient(const std::string& server_ip, int rest_port, int ws_port, bool log_to_file)
    : host(server_ip), restPort(rest_port), wsPort(ws_port), logToFile(log_to_file), stopClient(false) {
    globalClientInstance = this;
    signal(SIGINT, SystemStatClient::globalSignalHandler);
}

/**
 * @brief Destructor to clean up WebSocket resources.
 */
SystemStatClient::~SystemStatClient() {
    stopClient = true;
    if (wsClient) {
        boost::system::error_code ec;
        wsClient->close(websocket::close_code::normal, ec);
        wsClient.reset();
    }
}

/**
* @brief Saves system statistics (boot count and uptime) to a CSV file.
* 
* @param boot_count The system's boot count.
* @param uptime The system's uptime in seconds.
*/
void SystemStatClient::saveStatsToCSV(int boot_count, long uptime) 
{
    std::ifstream fileCheck(CSV_FILE_PATH);
    bool fileExists = fileCheck.good();
    bool isEmpty = fileCheck.peek() == std::ifstream::traits_type::eof();
    fileCheck.close();

    std::ofstream file(CSV_FILE_PATH, std::ios_base::app);
    if (!fileExists || isEmpty) {
        file << "Date(YYYY-MM-DD), Time(HH:MM:SS), Boot Count, Uptime (seconds)\n";
    }

    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);
    file << std::put_time(local_time, "%Y-%m-%d, %H:%M:%S") << ", " << boot_count << ", " << uptime << "\n";
}

/**
 * @brief Requests the initial system statistics from the server using the REST API.
 * 
 * @param host The server IP address.
 * @param restPort The port number of the REST API server.
 * @param logToFile Flag indicating whether to log the stats to a CSV file.
 */
void SystemStatClient::requestInitialStats() {
    httplib::Client client(host, restPort);
    auto res = client.Get("/fetchSystemStats");

    if (res && res->status == 200) {
        json stats = json::parse(res->body);
        std::cout << "[Received Stats] Boot Count: " << stats["boot_count"]
                  << ", Uptime: " << stats["uptime"] << " seconds\n";

        if (logToFile) {
            saveStatsToCSV(stats["boot_count"], stats["uptime"]);
            std::cout << "Initial stats saved to CSV file.\n";
        }
    } else {
        std::cerr << "Failed to fetch initial stats. Status: " 
                  << (res ? res->status : -1) << "\n";
    }
}

/**
 * @brief Establishes a WebSocket connection to receive periodic system statistics.
 * 
 * @param host The server IP address.
 * @param wsPort The port number of the WebSocket server.
 */
void SystemStatClient::connectToWebSocket() {
    boost::asio::io_context ioc;
    ip::tcp::resolver resolver(ioc);
    auto endpoints = resolver.resolve(host, std::to_string(wsPort));

    wsClient = std::make_shared<websocket::stream<ip::tcp::socket>>(ioc);
    boost::asio::connect(wsClient->next_layer(), endpoints);
    wsClient->handshake(host, "/");

    boost::beast::flat_buffer buffer;
    boost::system::error_code ec;

    while (!stopClient) {
        wsClient->read(buffer, ec);
        if (ec) {
            if (ec == websocket::error::closed) {
                std::cout << "WebSocket closed by server.\n";
                break;
            } else {
                std::cerr << "Error receiving periodic stats: " << ec.message() << "\n";
                break;
            }
        }

        std::string periodicData = boost::beast::buffers_to_string(buffer.data());
        json periodicStats = json::parse(periodicData);

        std::cout << "[Periodic Update] Boot Count: " << periodicStats["boot_count"]
                  << ", Uptime: " << periodicStats["uptime"] << " seconds\n";

        buffer.consume(buffer.size());
    }

    std::cout << "Client exiting WebSocket gracefully.\n";
    wsClient.reset();
}

/**
 * @brief Handles the SIGINT (Ctrl+C) signal to safely close the WebSocket connection and exit.
 * 
 * @param signum The signal number received.
 */
void SystemStatClient::signalHandler(int signum) {
    std::cout << "\nClient received SIGINT, closing WebSocket...\n";
    stopClient = true;

    if (wsClient) {
        boost::system::error_code ec;
        wsClient->close(websocket::close_code::normal, ec);
        if (ec) {
            std::cerr << "Error closing WebSocket: " << ec.message() << "\n";
        } else {
            std::cout << "WebSocket closed successfully.\n";
        }
    }

    wsClient.reset();
    exit(signum);
}

/**
 * @brief Static function to handle SIGINT (Ctrl+C).
 */
void SystemStatClient::globalSignalHandler(int signum) {
    if (globalClientInstance) {
        globalClientInstance->signalHandler(signum);
    }
}
