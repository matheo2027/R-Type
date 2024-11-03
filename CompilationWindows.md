# Installation

***
A little intro about the installation.

If you are on Linux, check the following informations :[Readme](./Readme.md)

## Installing MSYS2 and C++ Compilers

1. **Download MSYS2** from the [official website](https://www.msys2.org/).
2. **Run the installer** and follow the setup instructions.
3. **Update the package database** and core system packages by running the following command in the MSYS2 terminal:

```bash
pacman -Syu
```
Close the terminal and reopen it to complete the update.

Install the required C++ compilers and tools by running:

```bash
pacman -S mingw-w64-x86_64-toolchain
```
This command installs the GCC compiler, GDB debugger, and other essential development tools.

Install SFML using pacman with the following command:

```bash
pacman -S mingw-w64-x86_64-sfml
```

Installation of dependencies is required:

Install Auto Format Code:

```bash
pacman -S astyle
```

Clone and start the project:

```bash
git clone git@github.com:matheo2027/R-Type.git
cd ./R-Type

# If you want to compile the project :
./CompileWindows.sh

# If you want to delete all the documentation files and stop the project :
./StopAllWindows.sh

#In one terminal :
./build/client/r-type_client.exe

#In the seconde:
./build/server/r-type_server.exe
```
Don't forgot to ```chmod +x``` all the .sh files.
If you have some issues make ```dos2unix``` with the ```.sh```
Before any push please make sure the code is formatted properly with ```Astyle```.