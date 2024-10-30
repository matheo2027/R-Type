/**
 * @file Bullet.hpp
 * @brief Declaration of the Bullet component.
 *
 * This file defines the Bullet component, which is used to represent a bullet in the game.
 * It contains the properties of a bullet, such as speed and angle.
 */

#ifndef BULLET_HPP
#define BULLET_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Bullet
 * @brief Represents a bullet in the game.
 *
 * The Bullet struct inherits from the Component class and contains information about
 * the bullet's speed and angle.
 */
struct Bullet : public Component {
    /** The speed of the bullet. */
    float speed; /**< Speed of the bullet in units per second. */
    float angle; /**< Angle at which the bullet is fired in degrees. */

    /**
     * @brief Constructs a Bullet component.
     *
     * @param speed The speed of the bullet.
     * @param angle The angle at which the bullet is fired.
     */
    Bullet(float speed, float angle)
        : speed(speed), angle(angle)
    {
    }
};

} // namespace component

#endif // BULLET_HPP
