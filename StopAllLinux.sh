# Nettoie le cache CMake si nécessaire
rm -rf CMakeCache.txt CMakeFiles Doxyfile *.cmake CMakeDoxyfile.in Makefile ecs/Makefile ecs/*.cmake ecs/CMakeFiles client/Makefile client/*.cmake client/CMakeFiles server/Makefile server/*.cmake server/CMakeFiles

# Remove dependences SFML
sudo dnf remove libudev-devel openal-soft-devel libvorbis-devel libogg-devel flac-devel

# Suppr le dossier build
rm -rf build