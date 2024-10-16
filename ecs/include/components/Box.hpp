#ifndef BOX_HPP
#define BOX_HPP

#include "Component.hpp"

namespace component {

struct Box : public Component {
    int x;
    int y;
    int width;
    int height;

    Box(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    bool testCollision(const Box &other) const {
        return x < other.x + other.width &&
               x + width > other.x &&
               y < other.y + other.height &&
               y + height > other.y;
    }
};

}

#endif // BOX_HPP