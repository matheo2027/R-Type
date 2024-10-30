cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Vérification et inclusion de SFML
find_package(SFML 2.5 COMPONENTS graphics system window REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found, please install it.")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
