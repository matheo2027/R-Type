#include "SystemManager.hpp"

namespace ecs
{

SystemManager::SystemManager()
{
}

void SystemManager::update(float dt)
{
    for (auto &system : systems) {
        system->update(dt);
    }
}

}