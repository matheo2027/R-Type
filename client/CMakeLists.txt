cmake_minimum_required(VERSION 3.10)

project(r-type_client)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Inclusion des répertoires d'en-têtes
include_directories(${CMAKE_SOURCE_DIR}/ecs/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/SFML/include)

# Spécifiez les répertoires des bibliothèques ECS et SFML
link_directories(${CMAKE_BINARY_DIR}/ecs)
link_directories(${CMAKE_SOURCE_DIR}/third_party/SFML/lib)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Liaison avec ECS et SFML
target_link_libraries(${PROJECT_NAME} r-type_ecs sfml-graphics sfml-system sfml-window sfml-network)
