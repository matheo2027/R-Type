cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Pour éviter d'utiliser les extensions spécifiques au compilateur

# Specify the project name
project(r-type)

# SFML
add_subdirectory(lib/SFML)

# Add subdirectories
add_subdirectory(ecs)
add_subdirectory(client)
add_subdirectory(server)

# Compilation options
set(CMAKE_CXX_STANDARD 11)  # Use the desired C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
