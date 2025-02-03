# Supprimer le dossier de build existant
rm -rf build

# Générer et compiler le projet avec CMake
cmake -S . -B build  && cmake --build build
