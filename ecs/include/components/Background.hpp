#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Component.hpp"

namespace component {

struct Background : public Component {
    float speed;        // Vitesse de défilement
    float resetX;       // Position X de réinitialisation
    float width;        // Largeur de l'image

    Background(float speed = 100.0f, float resetX = 800.0f, float width = 800.0f)
        : speed(speed), resetX(resetX), width(width) {}
};

} // namespace component

#endif // BACKGROUND_HPP