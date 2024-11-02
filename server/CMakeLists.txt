cmake_minimum_required(VERSION 3.10)

project(r-type_server)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Inclusion des répertoires d'en-têtes
include_directories(include)

# SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")
set(SFML_INCLUDE "${SFML_DIR}/include")

# r_type_ecs
set(R_TYPE_ECS_DIR "${CMAKE_SOURCE_DIR}/ecs")
set(R_TYPE_ECS_INCLUDE "${R_TYPE_ECS_DIR}/include")

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE} ${R_TYPE_ECS_INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-network r-type_ecs)
