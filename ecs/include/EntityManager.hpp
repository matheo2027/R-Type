/**
 * @file EntityManager.hpp
 * @brief Manages entities and their components in an Entity-Component-System (ECS) architecture.
 */

#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <any>

#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "components/Network.hpp"
#include "components/Health.hpp"
#include "components/Texture.hpp"
#include "components/Player.hpp"
#include "components/Bullet.hpp"
#include "components/Enemie.hpp"
#include "components/Box.hpp"
#include "Entity.hpp"

#include <iostream>

namespace ecs {

/**
 * @class EntityManager
 * @brief Class responsible for managing entities and their associated components.
 *
 * The EntityManager handles the creation of entities and their components,
 * allowing for dynamic addition, retrieval, and removal of components associated
 * with each entity. This is part of the Entity-Component-System (ECS) pattern,
 * which promotes a separation of data and behavior.
 */
class EntityManager {
public:
    /**
     * @brief Constructs an EntityManager instance.
     */
    EntityManager();

    /**
     * @brief Adds a component to an entity.
     *
     * This method creates a new component of type T for the specified entity.
     *
     * @tparam T The type of the component to be added.
     * @tparam Args Types of the constructor arguments for the component.
     * @param entity The entity to which the component will be added.
     * @param args Arguments to initialize the component.
     */
    template <typename T, typename... Args>
    void addComponent(Entity entity, Args&&... args);

    /**
     * @brief Retrieves a component of a specific type from an entity.
     *
     * This method returns a pointer to the component of type T associated with
     * the specified entity.
     *
     * @tparam T The type of the component to retrieve.
     * @param entity The entity from which to retrieve the component.
     * @return A pointer to the component of type T, or nullptr if not found.
     */
    template <typename T>
    T* getComponent(Entity entity);

    /**
     * @brief Removes an entity and its associated components.
     *
     * This method resets all components associated with the specified entity.
     *
     * @param entity The entity to remove.
     */
    void removeEntity(Entity entity);

    /**
     * @brief Creates a new entity.
     *
     * This method generates a new entity and returns its ID.
     *
     * @return The ID of the newly created entity.
     */
    Entity createEntity();

    /**
     * @brief Gets the number of entities managed by the EntityManager.
     *
     * @return The number of entities.
     */
    unsigned int size() const;

private:
    std::unordered_map<std::type_index, std::vector<std::any>> m_components; ///< Map of component types to their instances.
    int m_size = 0; ///< The current number of entities managed.
};

} // namespace ecs
