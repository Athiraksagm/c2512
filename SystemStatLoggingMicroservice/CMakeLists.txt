cmake_minimum_required(VERSION 3.10)
project(SystemStatLogging)

set(CMAKE_CXX_STANDARD 14)

# Add paths for the includes and libraries
include_directories(include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the server and client executables
add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

# Add the tests
add_executable(test_system_stats test/test_system_stats.cpp)

# Link GTest with the tests
target_link_libraries(test_system_stats ${GTEST_LIBRARIES} pthread)

# Link server and client with necessary libraries
target_link_libraries(server pthread tinyxml2)
target_link_libraries(client pthread)

# Install CMake files
install(TARGETS server client DESTINATION bin)
