# Supprime le dossier de build
rm -rf build

# Définir le chemin vers MSYS2 MinGW64 comme CMAKE_PREFIX_PATH
export CMAKE_PREFIX_PATH="/C/msys64/mingw64"

# Définit le générateur CMake pour utiliser MinGW (gcc)
cmake -G "MinGW Makefiles" -S . -B build

# Lancer la compilation
cmake --build build
