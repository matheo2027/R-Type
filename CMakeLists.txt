cmake_minimum_required(VERSION 3.10)

project(rtype)

include_directories(client/include components/include)

file(GLOB_RECURSE CLIENT_SOURCES "client/src/*.cpp")
file(GLOB_RECURSE COMPONENTS_SOURCES "components/src/*.cpp")

add_executable(rtype ${CLIENT_SOURCES} ${COMPONENTS_SOURCES})

target_link_libraries(rtype sfml-graphics sfml-window sfml-system)
