cmake_minimum_required(VERSION 3.10)

project(r-type_client)

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

include_directories(include)

link_directories(${CMAKE_BINARY_DIR}/ecs)

add_executable(${PROJECT_NAME} ${SOURCES})

# Lien avec la bibliothèque ECS
target_link_libraries(${PROJECT_NAME} r-type_ecs)
