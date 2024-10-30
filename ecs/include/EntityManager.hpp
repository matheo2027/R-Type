/**
 * @file EntityManager.hpp
 * @brief This file contains the definition of the EntityManager class, which manages components for entities in an ECS (Entity-Component-System) architecture.
 *
 * The EntityManager class allows for adding, retrieving, and removing components associated with entities.
 * It uses type indexing to store components and provides methods to manage entities efficiently.
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

namespace ecs
{

/**
 * @class EntityManager
 * @brief Manages the components for entities in an ECS architecture.
 *
 * The EntityManager allows for the addition, retrieval, and removal of components associated with entities.
 * It handles the storage of components using type indexing and ensures efficient memory management.
 */
class EntityManager
{
    public:
        /**
         * @brief Constructs an EntityManager.
         */
        EntityManager();

        /**
         * @brief Adds a component of type T to the specified entity.
         *
         * This method resizes the internal storage for components if necessary and constructs a new component using the provided arguments.
         *
         * @tparam T The type of the component to add.
         * @tparam Args The types of the arguments used to construct the component.
         * @param entity The entity to which the component will be added.
         * @param args Arguments used to construct the component of type T.
         */
        template <typename T, typename... Args>
        void addComponent(Entity entity, Args&&... args);

        /**
         * @brief Retrieves a component of type T associated with the specified entity.
         *
         * This method returns a pointer to the component if it exists, or nullptr if it does not.
         *
         * @tparam T The type of the component to retrieve.
         * @param entity The entity from which the component will be retrieved.
         * @return A pointer to the component of type T, or nullptr if it does not exist.
         */
        template <typename T>
        T* getComponent(Entity entity);

        /**
         * @brief Removes all components associated with the specified entity.
         *
         * This method resets all components for the given entity, effectively removing it from the system.
         *
         * @param entity The entity to remove.
         */
        void removeEntity(Entity entity);

        /**
         * @brief Creates a new entity and returns its ID.
         *
         * The ID is unique and incremented for each new entity created.
         *
         * @return The ID of the newly created entity.
         */
        Entity createEntity();

        /**
         * @brief Returns the total number of entities managed by the EntityManager.
         *
         * @return The number of entities.
         */
        unsigned int size() const;

    private:
        std::unordered_map<std::type_index, std::vector<std::any>> m_components; ///< Map of components indexed by type.
        int m_size = 0; ///< The total number of entities managed.
};

} // namespace ecs
