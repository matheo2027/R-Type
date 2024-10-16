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


class EntityManager
{
    public:
        EntityManager();

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

        template <typename T>
        T* getComponent(Entity entity)
        {
            auto it = m_components.find(typeid(T));
            if (it != m_components.end() && it->second.size() > entity) {
                return std::any_cast<T>(&it->second[entity]);
            }
            return nullptr;
        }

        void removeEntity(Entity entity)
        {
            for (auto &[type, components] : m_components) {
                if (components.size() > entity) {
                    components[entity].reset();
                }
            }
        }

        Entity createEntity()
        {
            return m_size;
        }

        unsigned int size() const { return m_size; }

    private:
        std::unordered_map<std::type_index, std::vector<std::any>> m_components;
        int m_size = 0;

};

}

