#include "gtest/gtest.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <atomic>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sstream>

using json = nlohmann::json;

std::atomic<int> boot_count(0);
std::atomic<long> total_uptime(0);

struct sysinfo mock_sysinfo;
int sysinfo(struct sysinfo *info)
{
    info->uptime = 1000; 
    return 0; 
}

int loadBootCount()
{
    return 1; 
}

void saveBootCount(int count)
{
    std::ofstream file("boot_count.txt");
    file << count;
}

void updateSystemStats()
{
    struct sysinfo info;
    if (sysinfo(&info) == 0)
    {
        total_uptime.store(info.uptime); 
    }

    int current_count = loadBootCount();
    boot_count.store(current_count + 1);
    saveBootCount(boot_count.load());
}

TEST(SystemStatsTest, BootCountIncrement)
{
    boot_count.store(0);
    updateSystemStats();
    EXPECT_EQ(boot_count.load(), 2);
}

TEST(SystemStatsTest, UptimeUpdate)
{
    total_uptime.store(0);
    updateSystemStats();
    EXPECT_EQ(total_uptime.load(), 1000); 
}

TEST(SystemStatsTest, BootCountFileSave)
{
    saveBootCount(5);
    std::ifstream file("boot_count.txt");
    int count;
    file >> count;
    EXPECT_EQ(count, 5); 
}

TEST(SystemStatsTest, JsonResponseFormat)
{
    json response_json;
    response_json["boots"] = boot_count.load();
    response_json["uptime"] = total_uptime.load();

    std::string expected_json = "{\"boots\":2,\"uptime\":1000}";
    EXPECT_EQ(response_json.dump(), expected_json);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
