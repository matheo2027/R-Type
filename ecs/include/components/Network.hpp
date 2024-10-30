/**
 * @file NetworkComponent.hpp
 * @brief Contains the definition of the Network component.
 */

#ifndef NETWORKCOMPONENT_HPP
#define NETWORKCOMPONENT_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Network
 * @brief Represents a network component in the Entity-Component-System (ECS) architecture.
 *
 * The Network component holds the network ID associated with an entity.
 * It is used to identify the entity in network communications.
 */
struct Network : public Component {
    /// The unique identifier for the network.
    int networkId;

    /**
     * @brief Constructs a Network component.
     * @param networkId The unique network identifier (default is 0).
     */
    Network(int networkId = 0) : Component(), networkId(networkId) {}
};

}

#endif // NETWORKCOMPONENT_HPP
