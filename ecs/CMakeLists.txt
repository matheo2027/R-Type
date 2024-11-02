cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
