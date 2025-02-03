cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify the project name
project(r-type)

# Définition du chemin SFML dans third_party
set(SFML_DIR ${CMAKE_SOURCE_DIR}/third_party/SFML)

# Ajout des sous-projets
add_subdirectory(ecs)
add_subdirectory(client)
add_subdirectory(server)
