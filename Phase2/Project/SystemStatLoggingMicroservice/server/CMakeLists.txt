cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 14)

include_directories(include include)
add_executable(server source/server.cpp source/main.cpp source/tinyxml2.cpp)

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_server test/test_server.cpp ../source/server.cpp)
target_link_libraries(test_server PRIVATE tinyxml2 gtest gtest_main pthread)
add_test(NAME ServerTest COMMAND test_server)
