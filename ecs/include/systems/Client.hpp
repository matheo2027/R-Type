#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"
#include "network/ISocket.hpp"
#include "display/IDisplay.hpp"
#include "SFML/Network.hpp"

namespace systems
{

class Client : public ISystem
{
    public:
        Client(
            ecs::EntityManager &entityManager,
            sf::IpAddress address,
            unsigned short port,
            display::IDisplay &display
        );
        ~Client();
        void update(float dt);

        bool isConnected() const { return m_connected; }

    private:
        ecs::EntityManager &m_entityManager;
        sf::UdpSocket m_socket;
        unsigned short m_serverPort;
        sf::IpAddress m_serverAddress;
        display::IDisplay &m_display;

        void spawnEntity(ecs::Entity entity, float x, float y, const std::string &texture);
        void moveEntity(ecs::Entity entity, float x, float y);

        int m_id;
        bool m_connected = true;
};

}
