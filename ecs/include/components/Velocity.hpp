#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

namespace component {

struct Velocity : public Component {
    float vx;
    float vy;

    Velocity(float vx = 0, float vy = 0) : Component(), vx(vx), vy(vy) {}
};

}

#endif // VELOCITYCOMPONENT_HPP