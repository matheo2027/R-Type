#include <EntityManager.hpp>
#include <components/Position.hpp>
#include <display/SFMLDisplay.hpp>
#include <SystemManager.hpp>
#include <network/SFMLSocket.hpp>

#include <iostream>
#include <chrono>

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <server address> <server port>" << std::endl;
        return 1;
    }

    try {
        std::string serverID = argv[1];
        unsigned short serverPort = std::stoi(argv[2]);

        if (serverPort < 1024 || serverPort > 65535) {
            std::cerr << "Invalid port number. Please use a port between 1024 and 65535." << std::endl;
            return 84;
        }

        ecs::EntityManager entityManager;
        ecs::SystemManager systemManager;

        display::SFMLDisplay display;
        display.init(800, 600, "ECS Game"); 

        systemManager.addSystem<systems::Render>(entityManager, display);
        systemManager.addSystem<systems::Client>(entityManager, sf::IpAddress(serverID), serverPort, display);
        systemManager.addSystem<systems::ColorBlind>(entityManager, display);

        auto &client = systemManager.getSystem<systems::Client>();

        auto lastTime = std::chrono::high_resolution_clock::now();

        while (display.isOpen() && client.isConnected()) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            float dt = std::chrono::duration<float>(currentTime - lastTime).count();
            lastTime = currentTime;

            display.clear();

            systemManager.update(dt);

            display.update();
        }
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 84;
    }

    return 0;
}