cmake_minimum_required(VERSION 3.10)

project(rtype)

include_directories(client/include components/include)

file(GLOB_RECURSE CLIENT_SOURCES "client/src/*.cpp")
file(GLOB_RECURSE COMPONENTS_SOURCES "components/src/*.cpp")

add_executable(rtype ${CLIENT_SOURCES} ${COMPONENTS_SOURCES})

target_link_libraries(rtype sfml-graphics sfml-window sfml-system)



# Doxygen

find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ./Doxyfile.in)
    set(DOXYGEN_OUT ./Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Ajout pour créer le répertoire de sortie
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs)

    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else ()
    message("Doxygen needs to be installed to generate the documentation.")
endif ()
