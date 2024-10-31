cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Pour éviter d'utiliser les extensions spécifiques au compilateur

# Specify the project name
project(r-type)

# Platform-specific configurations for SFML
if(WIN32)
    message(STATUS "Configuring for Windows")

    # Check if SFML is already installed
    if(NOT EXISTS "C:/SFML/lib/sfml-graphics-d.dll")
        message(STATUS "SFML not found. Installing SFML on Windows...")

        file(WRITE "${CMAKE_BINARY_DIR}/install_sfml.bat"
            "@echo off\n"
            "echo Installing SFML...\n"
            "SET SFML_VERSION=2.5.1\n"
            "SET SFML_DIR=C:\\SFML\n"
            "mkdir %SFML_DIR%\n"
            "curl -L https://www.sfml-dev.org/files/SFML-%SFML_VERSION%-windows-vc15-32-bit.zip -o sfml.zip\n"
            "curl -L https://www.sfml-dev.org/files/SFML-%SFML_VERSION%-windows-vc15-64-bit.zip -o sfml_x64.zip\n"
            "echo Extracting files...\n"
            "powershell -Command \"Expand-Archive -Path sfml.zip -DestinationPath %SFML_DIR%\"\n"
            "powershell -Command \"Expand-Archive -Path sfml_x64.zip -DestinationPath %SFML_DIR%\"\n"
            "echo SFML installed successfully at %SFML_DIR%.\n"
        )

        message(STATUS "To install SFML, run the script: ${CMAKE_BINARY_DIR}/install_sfml.bat")
    else()
        message(STATUS "SFML is already installed.")
    endif()

elseif(UNIX)
    message(STATUS "Configuring for Unix (Linux)")

    # Set SFML_DIR to the expected location for SFML installation
    set(SFML_DIR "/usr/lib/cmake/SFML")

    # Check if SFML is already installed by trying to find it
    find_package(SFML REQUIRED COMPONENTS graphics window system network)

    if(NOT SFML_FOUND)
        message(STATUS "SFML not found. Installing SFML...")

        # Install SFML on Ubuntu
        execute_process(
            COMMAND sudo dnf install -y SFML-devel
            RESULT_VARIABLE install_result
            ERROR_VARIABLE install_error
        )

        if(NOT install_result EQUAL 0)
            message(FATAL_ERROR "Error installing SFML: ${install_error}")
        else()
            message(STATUS "SFML installed successfully.")
        endif()

        # Try finding SFML again after installation
        find_package(SFML REQUIRED COMPONENTS graphics window system network)
    endif()

    if(NOT SFML_FOUND)
        message(FATAL_ERROR "SFML was not found after installation. Please check your installation.")
    endif()
endif()

# Add subdirectories
add_subdirectory(ecs)
add_subdirectory(client)
add_subdirectory(server)

# Dependency configuration
if(WIN32)
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # Modify this path according to your SFML installation
    find_package(SFML REQUIRED COMPONENTS graphics window system)
elseif(UNIX)
    find_package(SFML REQUIRED COMPONENTS graphics window system network)
endif()

# Compilation options
set(CMAKE_CXX_STANDARD 11)  # Use the desired C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
