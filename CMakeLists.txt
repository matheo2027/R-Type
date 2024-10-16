cmake_minimum_required(VERSION 3.10)

project(r-type)

add_subdirectory(ecs)
add_subdirectory(client)
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