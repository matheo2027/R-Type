#include "systems/Server.hpp"
#include "protocole.hpp"
#include "network/SFMLSocket.hpp"

namespace systems
{

Server::Server(ecs::EntityManager &entityManager) 
    : m_entityManager(entityManager)
{
    if (m_socket.bind(4242) != sf::Socket::Done) {
        throw std::runtime_error("Failed to bind server socket.");
    }

    m_socket.setBlocking(false);
}

void Server::update(float dt)
{
    sf::IpAddress address;
    unsigned short port;
    sf::Packet packet;

    int packetsProcessed = 0;

    while (m_socket.receive(packet, address, port) == sf::Socket::Done && packetsProcessed < MAX_PACKET_PER_FRAME) {
        int type = 0;
        packet >> type;

        switch (type) {
            case messageType::CONNECT: {
                spawnPlayer(address, port);
                break;
            }

            case messageType::DISCONNECT: {
                int id;
                packet >> id;
                m_entityManager.removeEntity(id);
                m_clients.erase(std::remove_if(m_clients.begin(), m_clients.end(), [id](const ClientInfo &client) {
                    return client.id == id;
                }), m_clients.end());
                break;
            }

            case messageType::KEY: {
                int id;
                bool up, down, left, right, space;

                packet >> id >> up >> down >> left >> right >> space;

                ecs::Entity entity = static_cast<ecs::Entity>(id);
                auto player = m_entityManager.getComponent<component::Player>(entity);
                auto velocity = m_entityManager.getComponent<component::Velocity>(entity);

                if (player) {
                    player->up = up;
                    player->down = down;
                    player->left = left;
                    player->right = right;
                    player->shoot = space;
                }

                break;
            }

            default:
                break;
        }

        packet.clear();
        packetsProcessed++;
    }

    sendPosition(dt);
}

void Server::sendPosition(float dt)
{
    for (auto &client : m_clients) {
        sf::Packet packet;
        packet << static_cast<int>(messageType::MOVE);

        int entityCount = 0;
        for (unsigned int i = 0; i < m_entityManager.size(); i++) {
            auto position = m_entityManager.getComponent<component::Position>(i);
            if (position) {
                entityCount++;
            }
        }

        packet << entityCount;

        for (unsigned int i = 0; i < m_entityManager.size(); i++) {
            auto position = m_entityManager.getComponent<component::Position>(i);
            if (position) {
                packet << static_cast<int>(i);
                packet << static_cast<int>(position->x);
                packet << static_cast<int>(position->y);
            }
        }

        if (m_socket.send(packet, client.address, client.port) != sf::Socket::Done) {
            throw std::runtime_error("Failed to send position message.");
        }

        packet.clear();
    }
}

void Server::spawnPlayer(sf::IpAddress address, unsigned short port)
{
    ecs::Entity player = m_entityManager.createEntity();

    m_entityManager.addComponent<component::Player>(player);
    m_entityManager.addComponent<component::Velocity>(player, 0.0f, 0.0f);
    m_entityManager.addComponent<component::Position>(player, 400, 300);

    sf::Packet packet;
    packet << static_cast<int>(messageType::CONNECT);
    packet << static_cast<int>(player);
    m_socket.send(packet, address, port);



    packet.clear();
    packet << static_cast<int>(messageType::ENTITY_CREATE);
    packet << static_cast<int>(player);
    packet << 400;
    packet << 300;
    packet << "assets/img/player.png";

    if (m_socket.send(packet, address, port) != sf::Socket::Done) {
        throw std::runtime_error("Failed to send spawn message.");
    }

    m_clients.push_back({static_cast<int>(player), address, port});
}

void Server::spawnEntity(ecs::Entity entity, int x, int y, const std::string &texture)
{
    sf::Packet packet;
    packet << static_cast<int>(messageType::ENTITY_CREATE);
    packet << static_cast<int>(entity);
    packet << x;
    packet << y;
    packet << texture;

    for (auto &client : m_clients) {
        if (m_socket.send(packet, client.address, client.port) != sf::Socket::Done) {
            throw std::runtime_error("Failed to send spawn message.");
        }
    }
}

void Server::destroyEntity(ecs::Entity entity)
{
    sf::Packet packet;
    packet << static_cast<int>(messageType::ENTITY_DESTROY);
    packet << static_cast<int>(entity);

    for (auto &client : m_clients) {
        if (m_socket.send(packet, client.address, client.port) != sf::Socket::Done) {
            throw std::runtime_error("Failed to send destroy message.");
        }
    }
    
}

}
