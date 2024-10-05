#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

namespace component {

struct Position {
    float x;
    float y;

    Position(float x = 0, float y = 0) : x(x), y(y) {}
};

}

#endif // POSITIONCOMPONENT_HPP