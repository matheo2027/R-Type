rm -rf build
rm -rf lib
git submodule update --init --recursive
cd lib/SFML
git checkout 2.6.1
cd ../..
cmake -S . -B build && cmake --build build