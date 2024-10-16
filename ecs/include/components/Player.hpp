#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Component.hpp"

namespace component {

struct Player : public Component {
    float speed = 100.0f;

    bool up;
    bool down;
    bool left;
    bool right;
    bool shoot;

    float shootingSpeed = 0.5f;
    float shootingCooldown = 0.0f;

    Player(float speed = 100.0f, float shootingSpeed = 0.5f)
        : speed(speed), shootingSpeed(shootingSpeed)
    {
    }
};

}

#endif // PLAYER_HPP