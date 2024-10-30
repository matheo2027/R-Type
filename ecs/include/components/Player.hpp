/**
 * @file Player.hpp
 * @brief Declaration of the Player component.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Player
 * @brief Represents the player character in the game.
 *
 * This structure inherits from the Component class and contains
 * attributes that define the player's movement, shooting speed,
 * and cooldown for shooting actions.
 */
struct Player : public Component {
    /// The speed at which the player moves.
    float speed = 100.0f;

    /// Boolean flag for moving up.
    bool up;

    /// Boolean flag for moving down.
    bool down;

    /// Boolean flag for moving left.
    bool left;

    /// Boolean flag for moving right.
    bool right;

    /// Boolean flag for shooting.
    bool shoot;

    /// The speed at which the player can shoot.
    float shootingSpeed = 0.5f;

    /// The cooldown time before the player can shoot again.
    float shootingCooldown = 0.0f;

    /**
     * @brief Constructs a Player object with specified speed and shooting speed.
     *
     * @param speed The movement speed of the player (default is 100.0f).
     * @param shootingSpeed The speed at which the player can shoot (default is 0.5f).
     */
    Player(float speed = 100.0f, float shootingSpeed = 0.5f)
        : speed(speed), shootingSpeed(shootingSpeed)
    {
    }
};

} // namespace component

#endif // PLAYER_HPP
