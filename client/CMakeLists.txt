cmake_minimum_required(VERSION 3.10)

project(r-type_client)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Inclusion des répertoires d'en-têtes
include_directories(include)

link_directories(${CMAKE_BINARY_DIR}/ecs)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} r-type_ecs)