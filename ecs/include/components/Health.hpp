#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Health
 * @brief Représente les points de vie d'une entité.
 *
 * Ce composant définit les points de vie actuels et maximum d'une entité.
 */
struct Health : public Component {
    int currentHealth; ///< Points de vie actuels.
    int maxHealth;     ///< Points de vie maximum.

    /**
     * @brief Constructeur du composant Health.
     *
     * @param maxHealth Points de vie maximum.
     */
    Health(int maxHealth = 2)
        : currentHealth(maxHealth), maxHealth(maxHealth) {}
};

}

#endif // HEALTH_HPP