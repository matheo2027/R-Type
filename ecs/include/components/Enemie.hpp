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
    /**
     * @brief The speed of the enemy.
     *
     * This value determines how fast the enemy moves in the game.
     * Default value is 100.0f.
     */
    float speed = 100.0f;

    /**
     * @brief The speed at which the enemy shoots.
     *
     * This value represents how quickly the enemy can shoot projectiles.
     * Default value is 0.5f.
     */
    float shootingSpeed = 0.5f;

    /**
     * @brief The cooldown time before the enemy can shoot again.
     *
     * This value indicates the time interval required before the enemy can fire
     * another shot. Default value is 0.0f.
     */
    float shootingCooldown = 0.0f;

    /**
     * @brief Constructs an Enemie instance.
     *
     * @param speed The speed of the enemy (default is 100.0f).
     * @param shootingSpeed The shooting speed of the enemy (default is 0.5f).
     */
    Enemie(float speed = 100.0f, float shootingSpeed = 0.5f)
        : speed(speed), shootingSpeed(shootingSpeed)
    {
    }
};

}

#endif // ENEMIE_HPP
