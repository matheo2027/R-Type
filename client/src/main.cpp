#include <EntityManager.hpp>
#include <components/Position.hpp>
#include <display/SFMLDisplay.hpp>
#include <SystemManager.hpp>
#include <network/SFMLSocket.hpp>
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
    ecs::EntityManager entityManager;
    ecs::SystemManager systemManager;

    display::SFMLDisplay display;
    display.init(800, 600, "ECS Game"); 

    systemManager.addSystem<systems::Render>(entityManager, display);
    systemManager.addSystem<systems::Client>(entityManager, sf::IpAddress::LocalHost, 4242, display);

    auto &client = systemManager.getSystem<systems::Client>();

    while (display.isOpen() && client.isConnected()) {
        display.clear();
        systemManager.update(0.0f);
        display.update();
    }
    return 0;
}