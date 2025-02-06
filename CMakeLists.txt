cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Nom du projet
project(r-type)

include(FetchContent)

# SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL SYSTEM)
FetchContent_MakeAvailable(SFML)

# Ajouter les sous-projets
add_subdirectory(ecs)
add_subdirectory(client)
add_subdirectory(server)
