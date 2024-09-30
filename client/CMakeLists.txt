cmake_minimum_required(VERSION 3.10)

project(client)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(client ${SOURCES})

target_link_libraries(client ws2_32)

add_definitions(-D_WIN32_WINNT=0x0601)