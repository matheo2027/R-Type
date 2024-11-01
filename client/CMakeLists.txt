cmake_minimum_required(VERSION 3.10)

project(r-type_client)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Inclusion des répertoires d'en-têtes
include_directories(include)

# Spécifiez les répertoires des bibliothèques ECS
link_directories(${CMAKE_BINARY_DIR}/ecs)

# SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")
set(SFML_INCLUDE "${SFML_DIR}/include")
set(SFML_LIB "${SFML_DIR}/lib")

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-network)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Liaison avec la bibliothèque ECS
target_link_libraries(${PROJECT_NAME} r-type_ecs)
