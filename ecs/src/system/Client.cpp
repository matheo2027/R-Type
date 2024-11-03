#include "systems/Client.hpp"
#include "protocole.hpp"
#include "network/SFMLSocket.hpp"
#include <iostream>

namespace systems
{

Client::Client(
    ecs::EntityManager &entityManager,
    sf::IpAddress address,
    unsigned short port,
    display::IDisplay &display
)
    : m_entityManager(entityManager), m_serverPort(port), m_serverAddress(address), m_display(display)
{
    if (m_socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
        throw std::runtime_error("Failed to bind client socket.");
    }

    m_socket.setBlocking(false);

    sf::Packet packet;
    packet << static_cast<int>(messageType::CONNECT);

    m_socket.send(packet, m_serverAddress, m_serverPort);
}

Client::~Client()
{
    sf::Packet packet;
    packet << static_cast<int>(messageType::DISCONNECT);
    packet << m_id;

    m_socket.send(packet, m_serverAddress, m_serverPort);
}

void Client::update(float dt)
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
                int id;
                packet >> id;

                m_id = id;

                break;
            }

            case messageType::DISCONNECT: {
                m_connected = false;
                break;
            }

            case messageType::ENTITY_CREATE: {
                int id;
                float x, y;
                std::string texture;

                packet >> id >> x >> y >> texture;

                spawnEntity(id, x, y, texture);
                break;
            }

            case messageType::ENTITY_DESTROY: {
                int id;
                packet >> id;

                m_entityManager.removeEntity(id);
                break;
            }

            case messageType::MOVE: {
                int entityCount = 0;
                packet >> entityCount;

                for (int i = 0; i < entityCount; i++) {
                    int id;
                    float x, y;
                    packet >> id >> x >> y;

                    moveEntity(id, x, y);
                }

                break;
            }

            default:
                break;
        }

        packet.clear();
        packetsProcessed++;
    }

    if (m_connected) {
        bool up = m_display.isKeyPressed(display::Key::K_UP);
        bool down = m_display.isKeyPressed(display::Key::K_DOWN);
        bool left = m_display.isKeyPressed(display::Key::K_LEFT);
        bool right = m_display.isKeyPressed(display::Key::K_RIGHT);
        bool space = m_display.isKeyPressed(display::Key::K_SPACE);

        packet.clear();
        packet << static_cast<int>(messageType::KEY);
        packet << m_id << up << down << left << right << space;

        m_socket.send(packet, m_serverAddress, m_serverPort);

        packet.clear();

        bool mouseLeft = m_display.isMouseButtonPressed(display::MouseButton::LEFT);
        bool mouseRight = m_display.isMouseButtonPressed(display::MouseButton::RIGHT);

        float mouseX, mouseY;
        m_display.getMousePosition(mouseX, mouseY);

        packet << static_cast<int>(messageType::MOUSE);
        packet << static_cast<int>(m_id);
        packet << static_cast<float>(mouseX);
        packet << static_cast<float>(mouseY);
        packet << static_cast<bool>(mouseLeft);
        packet << static_cast<bool>(mouseRight);

        m_socket.send(packet, m_serverAddress, m_serverPort);

        packet.clear();
    }
}

void Client::spawnEntity(ecs::Entity entity, float x, float y, const std::string &texture)
{
    auto tex = m_display.createTexture(texture);

    m_entityManager.addComponent<component::Position>(entity, x, y);
    m_entityManager.addComponent<component::Texture>(entity, tex);
}

void Client::moveEntity(ecs::Entity entity, float x, float y)
{
    auto position = m_entityManager.getComponent<component::Position>(entity);
    if (position) {
        position->x = x;
        position->y = y;
    }
}

}