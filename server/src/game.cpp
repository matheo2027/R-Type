#include "game.hpp"
#include "server.hpp"

Game::Game(asio::io_context &ioContext, u16 port)
    : m_server(std::make_unique<Server>(ioContext, port, *this))
{
}

void Game::start()
{
    m_running = true;
    m_server->start();
    m_thread = std::thread(&Game::run, this);
}

void Game::stop()
{
    m_running = false;
    m_server->stop();
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void Game::run()
{
    auto frameDuration = std::chrono::milliseconds(1000 / 60);

    while (m_running) {
        auto frameStart = std::chrono::steady_clock::now();

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameTime = frameEnd - frameStart;

        if (frameTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - frameTime);
        }
    }
}

void Game::addPlayer(const udp::endpoint &endpoint)
{
    if (m_players.find(endpoint) == m_players.end()) {
        Player newPlayer;
        newPlayer.name = "Player" + std::to_string(m_players.size() + 1);
        newPlayer.endpoint = endpoint;
        m_players[endpoint] = newPlayer;
        std::cout << "Player " << newPlayer.name << " connected" << std::endl;

        sendToAll("Player " + newPlayer.name + " has joined the game.", endpoint);
    }
}

void Game::removePlayer(const udp::endpoint &endpoint)
{
    auto it = m_players.find(endpoint);
    if (it != m_players.end()) {
        std::cout << "Player " << it->second.name << " disconnected" << std::endl;
        sendToAll("Player " + it->second.name + " has left the game.", endpoint);
        m_players.erase(it);
    }
}

void Game::handleMessage(const std::string &message, const udp::endpoint &endpoint)
{
    auto it = m_players.find(endpoint);
    if (it != m_players.end()) {
        std::string msg = message;
        msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());
        msg.erase(std::remove(msg.begin(), msg.end(), '\r'), msg.end());
        msg.erase(std::remove_if(msg.begin(), msg.end(), ::isspace), msg.end());

        if (msg == "exit") {
            std::cout << it->second.name << " disconnected" << std::endl;
            removePlayer(endpoint);
        } else {
            std::cout << it->second.name << ": " << msg << std::endl;
            sendToAll(it->second.name + ": " + msg, endpoint);
        }
    }
}

void Game::sendToAll(const std::string &message, const udp::endpoint &sender)
{
    for (const auto &pair : m_players) {
        if (pair.first != sender) {
            m_server->send(message, pair.first);
        }
    }
}
