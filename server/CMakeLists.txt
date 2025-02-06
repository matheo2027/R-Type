cmake_minimum_required(VERSION 3.11)

project(r-type_server)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

# Création de l'exécutable serveur
add_executable(${PROJECT_NAME} ${SOURCES})

# Inclusion des headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ecs/include)

# Liaison avec ECS et SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
    r-type_ecs sfml-network
)
