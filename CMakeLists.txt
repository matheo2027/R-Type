cmake_minimum_required(VERSION 3.10)

project(rtype)

include_directories(src)

file(GLOB_RECURSE sources "src/*.cpp")

add_executable(rtype ${sources})