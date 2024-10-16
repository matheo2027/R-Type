#ifndef BULLET_HPP
#define BULLET_HPP

#include "Component.hpp"

namespace component {

struct Bullet : public Component {
    float speed;
    float angle;

    Bullet(float speed, float angle)
        : speed(speed), angle(angle)
    {
    }
};

}

#endif // BULLET_HPP