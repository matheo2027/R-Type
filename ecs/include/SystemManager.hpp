#pragma once

#include "systems/Movement.hpp"
#include "systems/Render.hpp"
#include "systems/Player.hpp"
#include "systems/Enemie.hpp"
#include "systems/Bullet.hpp"
#include "systems/Box.hpp"


#include <vector>

namespace ecs
{

class SystemManager
{
    public:
        SystemManager();

        void update(float dt);

        template <typename T, typename... Args>
        void addSystem(Args &&...args)
        {
            systems.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

    private:
        std::vector<std::unique_ptr<systems::ISystem>> systems;

};

}