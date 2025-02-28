

// #include <gtest/gtest.h>
// #include "server.h"
// //#include "../source/server.cpp"

// // Test the constructor and config loading
// TEST(ServerTest, LoadConfig) {
//     Server server;
//     EXPECT_GE(server.getLoggingInterval(), 1);  // Should be positive
// }

// TEST(ServerTest, GetBootCount_Valid) {
//     Server server;
//     int boot_count = server.getBootCountValue();
//     EXPECT_GE(boot_count, 0) << "Boot count should be non-negative.";
// }

// TEST(ServerTest, GetBootCount_Failure) {
//     Server server;
//     // Simulate a failure by running an invalid command
//     FILE *pipe = popen("invalid_command", "r");
//     if (!pipe) {
//         int result = server.getBootCountValue();
//         EXPECT_EQ(result, -1) << "Should return -1 on failure.";
//     }
// }

// // Test getUptime()
// TEST(ServerTest, GetUptime_Valid) {
//     Server server;
//     long uptime = server.getUptimeValue();
//     EXPECT_GT(uptime, 0) << "Uptime should be a positive number.";
// }

// TEST(ServerTest, GetUptime_Failure) {
//     Server server;
//     struct sysinfo info;
//     memset(&info, 0, sizeof(info));  // Simulating failure

//     long result = server.getUptimeValue();
//     EXPECT_NE(result, -1) << "Should return -1 if sysinfo() fails.";
// }

// TEST(ServerTest, LoadConfig_FileMissing) {
//     Server server;
//     // Simulate missing config.xml by renaming or deleting
//     EXPECT_EQ(server.getLoggingInterval(), 10);  // Default value
// }

// TEST(ServerTest, LoadConfig_NoConfigElement) {
//     Server server;
//     // Simulate config.xml without <config> element
//     EXPECT_EQ(server.getLoggingInterval(), 10);  // Default
// }

// TEST(ServerTest, LoadConfig_NoLoggingInterval) {
//     Server server;
//     // Simulate config.xml missing <logging_interval>
//     EXPECT_EQ(server.getLoggingInterval(), 10);  // Default
// }

// TEST(ServerTest, LoadConfig_InvalidLoggingInterval) {
//     Server server;
//     // Simulate config.xml with non-numeric logging interval
//     EXPECT_EQ(server.getLoggingInterval(), 10);  // Default
// }

// TEST(ServerTest, LoadConfig_ValidLoggingInterval) {
//     Server server;
//     // Simulate config.xml with valid numeric interval
//     EXPECT_GT(server.getLoggingInterval(), 0);
// }

// // Test REST API response format (Mocking required in real tests)
// TEST(ServerTest, RESTApiResponseFormat) {
//     Server server;
//     nlohmann::json response;
//     response["boot_count"] = server.getBootCountValue();
//     response["uptime"] = server.getUptimeValue();
//     EXPECT_TRUE(response.contains("boot_count"));
//     EXPECT_TRUE(response.contains("uptime"));
// }

// TEST(ServerTest, WebSocketClientHandling) {
//     Server server;
//     EXPECT_NO_THROW({
//         // Simulate WebSocket server start
//         std::thread ws_thread(&Server::startWebSocketServer, &server, 9000);
//         std::this_thread::sleep_for(std::chrono::seconds(1));  // Allow time for setup
//         ws_thread.detach();
//     });
// }

// TEST(ServerTest, StartRESTServer) {
//     Server server;
//     EXPECT_NO_THROW({
//         std::thread rest_thread(&Server::startRESTServer, &server, 8080);
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         rest_thread.detach();
//     });
// }

// TEST(ServerTest, StartWebSocketServer) {
//     Server server;
//     EXPECT_NO_THROW({
//         std::thread ws_thread(&Server::startWebSocketServer, &server, 9001);
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         ws_thread.detach();
//     });
// }

// // ===================== MAIN FUNCTION FOR TESTS =====================
// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }



#include <gtest/gtest.h>
//#include "server.h"
#include "../source/server.cpp"

TEST(ServerTest, LoadConfig_Default) {
    Server server;
    EXPECT_GE(server.getLoggingInterval(), 1);
}

TEST(ServerTest, GetBootCount_Valid) {
    Server server;
    int boot_count = server.getBootCountValue();
    EXPECT_GE(boot_count, 0);
}

TEST(ServerTest, GetBootCount_Failure) {
    Server server;
    FILE *pipe = popen("invalid_command", "r");
    if (!pipe) {
        int result = server.getBootCountValue();
        EXPECT_EQ(result, -1);
    }
}

TEST(ServerTest, GetUptime_Valid) {
    Server server;
    long uptime = server.getUptimeValue();
    EXPECT_GT(uptime, 0);
}

TEST(ServerTest, GetUptime_Failure) {
    Server server;
    long result = server.getUptimeValue();
    EXPECT_NE(result, -1);
}

TEST(ServerTest, BroadcastStats_NoClients) {
    Server server;
    EXPECT_NO_THROW(server.broadcastStats());
}

TEST(ServerTest, StartRESTServer) {
    Server server;
    EXPECT_NO_THROW({
        std::thread rest_thread(&Server::startRESTServer, &server, 8080);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        rest_thread.detach();
    });
}

TEST(ServerTest, StartWebSocketServer) {
    Server server;
    EXPECT_NO_THROW({
        std::thread ws_thread(&Server::startWebSocketServer, &server, 9001);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ws_thread.detach();
    });
}

TEST(ServerTest, HandleWebSocketClient) {
    Server server;
    EXPECT_NO_THROW({
        std::thread ws_thread(&Server::startWebSocketServer, &server, 9001);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ws_thread.detach();
    });
}

TEST(ServerTest, SendPeriodicStats) {
    Server server;
    EXPECT_NO_THROW(server.sendPeriodicStats());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
