cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

# Affichage du chemin de configuration
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création d'une bibliothèque ECS statique
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Inclusion des headers
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/SFML/include)

# Spécifier SFML dans les dépendances
if(WIN32)
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
endif()
