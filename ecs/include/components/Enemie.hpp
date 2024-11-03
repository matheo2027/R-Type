/**
 * @file Enemie.hpp
 * @brief Header file for the Enemie component.
 *
 * This file defines the Enemie struct, which inherits from the Component class.
 * It contains properties related to the enemy's movement and shooting mechanics.
 */

#ifndef ENEMIE_HPP
#define ENEMIE_HPP

#include "Component.hpp"

namespace component {
/**
 * @struct Enemie
 * @brief Represents an enemy in the game.
 *
 * The Enemie struct inherits from the Component class and includes properties
 * that define the behavior of the enemy, including its speed and shooting
 * capabilities.
 */
struct Enemie : public Component {
    float speed = 100.0f;
    float shootingSpeed = 1.0f; // Temps entre chaque tir en secondes
    float shootingCooldown = 0.0f; // Temps restant avant le prochain tir

    Enemie(float speed = 100.0f, float shootingSpeed = 1.0f)
        : speed(speed), shootingSpeed(shootingSpeed), shootingCooldown(0.0f) {}
};

}
#endif // ENEMIE_HPP
