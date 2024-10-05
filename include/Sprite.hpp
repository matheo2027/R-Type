#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <string>

namespace component {

struct Sprite {
    std::string spritePath;

    Sprite(const std::string& spritePath = "") : spritePath(spritePath) {}
};

}

#endif // SPRITECOMPONENT_HPP