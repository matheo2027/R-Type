cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

find_package(SFML 2.5 COMPONENTS graphics system window REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)