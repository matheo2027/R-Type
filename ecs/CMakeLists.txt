cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# find_package(SFML 2.5 COMPONENTS graphics system window network REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} SFML-graphics SFML-system SFML-window SFML-network)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
endif()