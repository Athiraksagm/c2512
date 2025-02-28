cmake_minimum_required(VERSION 3.10)
project(Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(include include)
add_executable(client source/client.cpp source/main.cpp source/tinyxml2.cpp)
