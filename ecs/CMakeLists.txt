cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# sfml
set(SFML_DIR "{CMAKE_SOURCE_DIR}/lib/SFML)")
set(SFML_INCLUDE "{SFML_DIR}/include")

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-network)
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE})

target_include_directories(${PROJECT_NAME} PUBLIC include)