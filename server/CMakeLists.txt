cmake_minimum_required(VERSION 3.10)

project(r-type_server)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création de la bibliothèque statique
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")
set(SFML_INCLUDE "${SFML_DIR}/include")
set(SFML_LIB "${SFML_DIR}/lib")

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-network)

# Inclusion des répertoires d'en-têtes
target_include_directories(${PROJECT_NAME} PUBLIC include)
