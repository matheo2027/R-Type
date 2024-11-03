# Supprimer le dossier de build existant
rm -rf build

# Download SFML
sudo dnf install -y SFML-devel

# Générer et compiler le projet avec CMake
cmake -S . -B build && cmake --build build
