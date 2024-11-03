#include "systems/Server.hpp"
#include "protocole.hpp"
#include "network/SFMLSocket.hpp"

namespace systems
{

Server::Server(ecs::EntityManager &entityManager, unsigned short port)
    : m_entityManager(entityManager)
{
    if (m_socket.bind(port) != sf::Socket::Done) {
        throw std::runtime_error("Failed to bind server socket.");
    }

    m_socket.setBlocking(false);
}

Server::~Server()
{
    for (const auto &client : m_clients) {
        sf::Packet packet;
        packet << static_cast<int>(messageType::DISCONNECT);
        packet << client.id;

        m_socket.send(packet, client.address, client.port);
    }
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

        for (auto &client : m_clients) {
            if (client.address == address && client.port == port) {
                client.lastSend = 0.0f;
                break;
            }
        }

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

                destroyEntity(id);
                break;
            }

            case messageType::KEY: {
                int id;
                bool up, down, left, right, space;

                packet >> id >> up >> down >> left >> right >> space;

                ecs::Entity entity = static_cast<ecs::Entity>(id);
                auto player = m_entityManager.getComponent<component::Player>(entity);

                if (player && player->id == id) {
                    player->up = up;
                    player->down = down;
                    player->left = left;
                    player->right = right;
                    player->shoot = space;
                }

                break;
            }

            case messageType::MOUSE: {
                int id;
                bool left, right;
                float x, y;

                packet >> id >> x >> y >> left >> right;

                ecs::Entity entity = static_cast<ecs::Entity>(id);
                auto player = m_entityManager.getComponent<component::Player>(entity);

                if (player && player->id == id) {
                    player->mouseX = x;
                    player->mouseY = y;
                    player->mouseLeft = left;
                    player->mouseRight = right;
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

    timeOut(dt);
}

void Server::timeOut(float dt)
{
    for (auto it = m_clients.begin(); it != m_clients.end();) {
        it->lastSend += dt;
        if (it->lastSend > 5.0f) {
            m_entityManager.removeEntity(it->id);
            destroyEntity(it->id);
            it = m_clients.erase(it);
        } else {
            it++;
        }
    }
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
                packet << static_cast<float>(position->x);
                packet << static_cast<float>(position->y);
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

    auto playerComponent = m_entityManager.getComponent<component::Player>(player);
    playerComponent->id = player;


    sf::Packet packet;
    packet << static_cast<int>(messageType::CONNECT);
    packet << static_cast<int>(player);
    if (m_socket.send(packet, address, port) != sf::Socket::Done) {
        throw std::runtime_error("Failed to send connect message.");
    }


    for (const auto &existingClient : m_clients) {
        packet.clear();
        packet << static_cast<int>(messageType::ENTITY_CREATE);
        packet << static_cast<int>(existingClient.id);
        auto position = m_entityManager.getComponent<component::Position>(existingClient.id);
        if (!position) {
            continue;
        }
        packet << static_cast<float>(position->x);
        packet << static_cast<float>(position->y);
        packet << "assets/img/player.png";

        if (m_socket.send(packet, address, port) != sf::Socket::Done) {
            throw std::runtime_error("Failed to send spawn message.");
        }
    }

    m_clients.push_back({static_cast<int>(player), address, port});

    packet.clear();
    packet << static_cast<int>(messageType::ENTITY_CREATE);
    packet << static_cast<int>(player);
    packet << 400;
    packet << 300;
    packet << "assets/img/player.png";

    for (auto &client : m_clients) {
        if (m_socket.send(packet, client.address, client.port) != sf::Socket::Done) {
            throw std::runtime_error("Failed to send spawn message.");
        }
        sf::sleep(sf::milliseconds(10));
    }
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
