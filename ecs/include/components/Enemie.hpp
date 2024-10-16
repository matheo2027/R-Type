#ifndef ENEMIE_HPP
#define ENEMIE_HPP

#include "Component.hpp"

namespace component {

struct Enemie : public Component {
    float speed = 100.0f;

    float shootingSpeed = 0.5f;
    float shootingCooldown = 0.0f;

    Enemie(float speed = 100.0f, float shootingSpeed = 0.5f)
        : speed(speed), shootingSpeed(shootingSpeed)
    {
    }
};

}

#endif // ENEMIE_HPP