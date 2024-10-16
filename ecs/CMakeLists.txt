cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Spécifier le chemin de SFML si nécessaire
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML")

# Rechercher le package SFML
find_package(SFML 2.5 COMPONENTS graphics system window REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
