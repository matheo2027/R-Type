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
#include "components/Pattern.hpp"
#include "components/Background.hpp" // Ajoutez cette ligne
#include "Entity.hpp"

#include <iostream>

namespace ecs
{

/**
 * @class EntityManager
 * @brief Manages entities and their components in an ECS (Entity-Component-System) architecture.
 *
 * The EntityManager is responsible for creating entities and managing their associated components.
 * It allows the addition, retrieval, and removal of components associated with entities.
 */
class EntityManager
{
public:
    /**
     * @brief Constructs an EntityManager object.
     */
    EntityManager();

    /**
     * @brief Adds a component of type T to the specified entity.
     *
     * @tparam T The type of component to add.
     * @tparam Args The types of the arguments to construct the component.
     * @param entity The identifier of the entity to which the component will be added.
     * @param args The arguments to construct the component of type T.
     */
    template <typename T, typename... Args>
    void addComponent(Entity entity, Args&&... args)
    {
        auto &components = m_components[typeid(T)];
        if (components.size() <= entity) {
            components.resize(entity + 1);
            m_size = entity + 1;
        }
        components[entity] = T(std::forward<Args>(args)...);
    }

    /**
     * @brief Retrieves a pointer to the component of type T associated with the specified entity.
     *
     * @tparam T The type of the component to retrieve.
     * @param entity The identifier of the entity from which to retrieve the component.
     * @return A pointer to the component of type T if it exists, otherwise nullptr.
     */
    template <typename T>
    T* getComponent(Entity entity)
    {
        auto it = m_components.find(typeid(T));
        if (it != m_components.end() && it->second.size() > entity) {
            return std::any_cast<T>(&it->second[entity]);
        }
        return nullptr;
    }

    /**
     * @brief Removes all components associated with the specified entity.
     *
     * This function resets all components of the entity, effectively removing it from the EntityManager.
     *
     * @param entity The identifier of the entity to remove.
     */
    void removeEntity(Entity entity)
    {
        for (auto &[type, components] : m_components) {
            if (components.size() > entity) {
                components[entity].reset();
            }
        }
    }

    /**
     * @brief Creates a new entity and returns its identifier.
     *
     * @return The identifier of the newly created entity.
     */
    Entity createEntity()
    {
        return m_size;
    }

    /**
     * @brief Retrieves the total number of entities managed by the EntityManager.
     *
     * @return The number of entities.
     */
    unsigned int size() const { return m_size; }

private:
    std::unordered_map<std::type_index, std::vector<std::any>> m_components; /**< A map storing vectors of components indexed by their type. */
    int m_size = 0; /**< The current number of entities managed by the EntityManager. */
};

}
