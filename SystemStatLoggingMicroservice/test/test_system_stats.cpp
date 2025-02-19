#include "gtest/gtest.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <atomic>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sstream>
#include <array>
#include <memory>

using json = nlohmann::json;

std::atomic<int> boot_count(0);
std::atomic<long> total_uptime(0);

// Mock function to get boot count using shell command
int mock_getBootCount() {
    return 5;  // Mocked boot count
}

// Mock sysinfo function
struct sysinfo mock_sysinfo;
int sysinfo(struct sysinfo *info) {
    info->uptime = 3600;  // Mock uptime: 3600 seconds (1 hour)
    return 0;  // Mock success
}

// Mock function to save boot count (no actual file writes)
void mock_saveBootCount(int count) {
    std::ofstream file("mock_boot_count.txt");
    file << count;
}

// Function to update system stats (uses mock sysinfo)
void updateSystemStats() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        total_uptime.store(info.uptime);  // Mock uptime in seconds
    }

    boot_count.store(mock_getBootCount());  // Use mocked boot count
}

// **TEST 1: Boot count retrieval**
TEST(SystemStatsTest, BootCountRetrieval) {
    boot_count.store(mock_getBootCount());
    EXPECT_EQ(boot_count.load(), 5);  // Should match the mocked value
}

// **TEST 2: Uptime retrieval**
TEST(SystemStatsTest, UptimeRetrieval) {
    total_uptime.store(0);
    updateSystemStats();
    EXPECT_EQ(total_uptime.load(), 3600);  // Should be 3600 seconds
}

// **TEST 3: Boot count file save**
TEST(SystemStatsTest, BootCountFileSave) {
    mock_saveBootCount(8);
    std::ifstream file("mock_boot_count.txt");
    int count;
    file >> count;
    EXPECT_EQ(count, 8);  // The saved count should be 8
}

// **TEST 4: JSON response format**
TEST(SystemStatsTest, JsonResponseFormat) {
    json response_json;
    response_json["boot_count"] = boot_count.load();
    response_json["uptime"] = total_uptime.load();

    std::string expected_json = "{\"boot_count\":5,\"uptime\":3600}";
    EXPECT_EQ(response_json.dump(), expected_json);  // JSON should match expected format
}

// **MAIN FUNCTION**
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
