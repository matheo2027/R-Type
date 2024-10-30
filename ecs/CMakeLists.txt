cmake_minimum_required(VERSION 3.10)

project(r-type_ecs)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création de la bibliothèque statique
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Recherche de SFML
find_package(SFML 2.5 COMPONENTS graphics system window network REQUIRED)

# Inclusion des répertoires d'en-têtes
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Liaison des bibliothèques SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-network)
