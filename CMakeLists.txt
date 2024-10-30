cmake_minimum_required(VERSION 3.10)

project(r-type)

# Vérification de la présence de CMake et des outils de construction
include(CMakePackageConfigHelpers)

# Fonction pour installer une bibliothèque si elle n'est pas trouvée
function(find_and_install_package pkg_name)
    find_package(${pkg_name} REQUIRED)

    if(NOT ${pkg_name}_FOUND)
        message(STATUS "Installing ${pkg_name}...")
        execute_process(COMMAND sudo apt-get install -y ${pkg_name}
                        ERROR_VARIABLE install_error)
        if(install_error)
            message(FATAL_ERROR "Could not install ${pkg_name}: ${install_error}")
        endif()
        find_package(${pkg_name} REQUIRED)
    endif()
endfunction()

# Installer SFML si nécessaire
find_and_install_package(SFML)

add_subdirectory(ecs)
add_subdirectory(client)
add_subdirectory(server)
