#ifndef OWNER_HPP
#define OWNER_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Owner
 * @brief Représente le propriétaire d'une entité (par exemple, une balle).
 */
struct Owner : public Component {
    enum class Type {
        Player,
        Enemie
    };

    Type ownerType;

    Owner(Type ownerType) : ownerType(ownerType) {}
};

}

#endif // OWNER_HPP