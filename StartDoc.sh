# Nettoie le cache CMake si nécessaire
rm -rf CMakeCache.txt CMakeFiles Doxyfile *.cmake CMakeDoxyfile.in

# Génère les fichiers CMake
cmake .

# Compile la cible de documentation
cmake --build . --target doc_doxygen