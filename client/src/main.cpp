#include <EntityManager.hpp>
#include <components/Position.hpp>
#include <display/SFMLDisplay.hpp>
#include <SystemManager.hpp>
#include <systems/Render.hpp>
#include <systems/Player.hpp>
#include <systems/Movement.hpp>
#include <systems/Enemie.hpp> // Ajoutez cette ligne pour inclure le fichier d'en-tête Enemies.hpp
#include <systems/Bullet.hpp>
#include <systems/Box.hpp>
#include <components/Background.hpp>

#include <iostream>
#include <chrono>

int main()
{
    ecs::EntityManager manager;
    display::SFMLDisplay display;

    // Création du premier background
    ecs::Entity bg1 = manager.createEntity();
    manager.addComponent<component::Position>(bg1, 0, 0);
    std::shared_ptr<display::ITexture> bgTexture = display.createTexture("../assets/img/background.png");
    manager.addComponent<component::Texture>(bg1, bgTexture);
    manager.addComponent<component::Background>(bg1, 100.0f, 800.0f, 800.0f);

    // Création du deuxième background (pour la continuité)
    ecs::Entity bg2 = manager.createEntity();
    manager.addComponent<component::Position>(bg2, 800, 0);
    manager.addComponent<component::Texture>(bg2, bgTexture);
    manager.addComponent<component::Background>(bg2, 100.0f, 800.0f, 800.0f);

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
    manager.addComponent<component::Pattern>(enemie, -1.0f, 0.0f, 50.0f, 40.0f, 2.0f);

    ecs::Entity enemie1 = manager.createEntity();
    manager.addComponent<component::Position>(enemie1, 600, 300);
    manager.addComponent<component::Velocity>(enemie1, 0, 0);
    manager.addComponent<component::Enemie>(enemie1, 100.0f);
    texture = display.createTexture("../assets/img/enemie.png");
    manager.addComponent<component::Texture>(enemie1, texture);
    manager.addComponent<component::Box>(enemie1, 700, 300, 50, 50);
    manager.addComponent<component::Pattern>(enemie1, -1.0f, 0.0f, 50.0f, 40.0f, 2.0f);

    ecs::SystemManager systemManager;
    systemManager.addSystem<systems::Background>(manager, display);
    systemManager.addSystem<systems::Render>(manager, display);
    systemManager.addSystem<systems::Player>(manager, display);
    systemManager.addSystem<systems::Movement>(manager);
    systemManager.addSystem<systems::Enemie>(manager, display);
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