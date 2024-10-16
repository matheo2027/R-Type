#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "components/Component.hpp"

namespace component {

struct Position : public Component {
    float x;
    float y;

    Position(float x = 0, float y = 0) : Component(), x(x), y(y) {}
};

}

#endif // POSITIONCOMPONENT_HPP