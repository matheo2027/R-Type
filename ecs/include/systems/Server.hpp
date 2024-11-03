#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"
#include "network/ISocket.hpp"
#include "SFML/Network.hpp"

namespace systems
{

struct ClientInfo
{
    int id;
    sf::IpAddress address;
    unsigned short port;
};

class Server : public ISystem
{
    public:
        Server(ecs::EntityManager &entityManager);
        void update(float dt);

        void spawnEntity(ecs::Entity entity, int x, int y, const std::string &texture);
        void destroyEntity(ecs::Entity entity);

    private:
        ecs::EntityManager &m_entityManager;
        sf::UdpSocket m_socket;

        void sendPosition(float dt);
        void spawnPlayer(sf::IpAddress address, unsigned short port);

        std::vector<ClientInfo> m_clients;
};

}