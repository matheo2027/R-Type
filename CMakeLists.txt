cmake_minimum_required(VERSION 3.10)
project(r-type)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajouter SFML comme sous-répertoire
add_subdirectory(lib/SFML)

# Ajouter les sous-répertoires pour les différentes parties du projet
add_subdirectory(ecs)
add_subdirectory(client)
#add_subdirectory(server)