#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

namespace component {

struct Velocity {
    float vx;
    float vy;

    Velocity(float vx = 0, float vy = 0) : vx(vx), vy(vy) {}
};

}

#endif // VELOCITYCOMPONENT_HPP