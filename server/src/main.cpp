#include "SystemManager.hpp"
#include "network/SFMLSocket.hpp"

#include <chrono>
#include <thread>

int main()
{
    ecs::EntityManager entityManager;
    ecs::SystemManager systemManager;

    systemManager.addSystem<systems::Server>(entityManager, 4242);
    systems::Server &server = systemManager.getSystem<systems::Server>();

    ecs::Entity test = entityManager.createEntity();
    entityManager.addComponent<component::Position>(test, 0.0f, 0.0f);
    entityManager.addComponent<component::TextureServer>(test, "assets/img/player.png");

    systemManager.addSystem<systems::Movement>(entityManager);
    systemManager.addSystem<systems::Player>(entityManager, server);
    systemManager.addSystem<systems::Enemie>(entityManager);
    systemManager.addSystem<systems::Bullet>(entityManager);
    systemManager.addSystem<systems::Box>(entityManager);

    auto lastTime = std::chrono::high_resolution_clock::now();
    const float targetFrameTime = 1.0f / 60.0f;

    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        systemManager.update(dt);

        float remainingTime = targetFrameTime - dt;
        if (remainingTime > 0) {
            std::this_thread::sleep_for(std::chrono::duration<float>(remainingTime));
        }
    }

    return 0;
}