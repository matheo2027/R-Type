# Supprimer le dossier de build existant
rm -rf build

# Insatll dependences SFML
sudo dnf install libudev-devel openal-soft-devel libvorbis-devel libogg-devel flac-devel

# Générer et compiler le projet avec CMake
cmake -S . -B build  && cmake --build build
