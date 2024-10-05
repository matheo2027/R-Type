#ifndef TEXTURECOMPONENT_HPP
#define TEXTURECOMPONENT_HPP

#include <string>

namespace component {

struct Texture {
    std::string texturePath;

    Texture(const std::string& texturePath = "") : texturePath(texturePath) {}
};

}

#endif // TEXTURECOMPONENT_HPP