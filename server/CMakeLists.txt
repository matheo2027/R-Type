cmake_minimum_required(VERSION 3.10)

project(server)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(server ${SOURCES})

target_link_libraries(server ws2_32)