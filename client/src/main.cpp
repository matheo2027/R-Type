#include <EntityManager.hpp>
#include <components/Position.hpp>
#include <display/SFMLDisplay.hpp>
#include <SystemManager.hpp>

#include <iostream>
#include <chrono>

int main()
{
    ecs::EntityManager manager;
    display::SFMLDisplay display;

    ecs::Entity player = manager.createEntity();

    manager.addComponent<component::Position>(player, 300, 300);
    manager.addComponent<component::Velocity>(player, 0, 0);

    std::shared_ptr<display::ITexture> texture = display.createTexture("../assets/img/player.png");
    manager.addComponent<component::Texture>(player, texture);
    manager.addComponent<component::Player>(player, 100.0f);

    ecs::Entity enemie = manager.createEntity();

    manager.addComponent<component::Position>(enemie, 700, 300);
    manager.addComponent<component::Velocity>(enemie, 0, 0);
    manager.addComponent<component::Enemie>(enemie, 100.0f);

    texture = display.createTexture("../assets/img/enemie.png");
    manager.addComponent<component::Texture>(enemie, texture);
    manager.addComponent<component::Box>(enemie, 700, 300, 50, 50);

    ecs::SystemManager systemManager;

    systemManager.addSystem<systems::Render>(manager, display);
    systemManager.addSystem<systems::Player>(manager, display);
    systemManager.addSystem<systems::Movement>(manager);
    systemManager.addSystem<systems::Enemie>(manager);
    systemManager.addSystem<systems::Bullet>(manager);
    systemManager.addSystem<systems::Box>(manager);

    display.init(800, 600, "ECS");

    auto start = std::chrono::high_resolution_clock::now();

    while(display.isOpen()) {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = now - start;
        float dt = elapsed.count();

        display.clear();

        systemManager.update(dt);

        display.update();

        start = now;
    }

    return 0;
}
