cmake_minimum_required(VERSION 3.10)

project(r-type_server)

# Recherche des fichiers sources
file(GLOB_RECURSE SOURCES src/*.cpp)

# Exclusion des fichiers indésirables
list(FILTER SOURCES EXCLUDE REGEX "\\.css$")

include_directories("C:/msys64/mingw64/include")

# Inclusion des répertoires d'en-têtes
include_directories(include)

# Spécifiez les répertoires des bibliothèques ECS
link_directories(${CMAKE_BINARY_DIR}/ecs)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Liaison avec la bibliothèque ECS
target_link_libraries(${PROJECT_NAME} r-type_ecs)
