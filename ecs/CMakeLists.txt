cmake_minimum_required(VERSION 3.11)

project(r-type_ecs)

# Affichage des chemins de configuration
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création de la bibliothèque ECS statique
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Inclusion des headers
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Lien avec SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics sfml-system sfml-window sfml-network
)
