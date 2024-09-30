#pragma once

#include "type.hpp"

#include <iostream>
#include <asio.hpp>
#include <unordered_map>
#include <memory>
#include <thread>
#include <ctype.h>

using asio::ip::udp;

class Server;

struct Player {
    std::string name;
    udp::endpoint endpoint;
};

class Game
{
    public:
        Game(asio::io_context &ioContext, u16 port);
        void start();
        void stop();
        void run();
        void addPlayer(const udp::endpoint &endpoint);
        void removePlayer(const udp::endpoint &endpoint);
        void handleMessage(const std::string &message, const udp::endpoint &endpoint);

    private:
        void sendToAll(const std::string &message, const udp::endpoint &sender = udp::endpoint());

        std::unordered_map<udp::endpoint, Player, std::hash<udp::endpoint>> m_players;
        std::unique_ptr<Server> m_server;

        bool m_running = false;

        std::thread m_thread;
};