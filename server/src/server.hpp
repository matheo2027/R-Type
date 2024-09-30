#pragma once

#include <iostream>
#include <string>
#include <asio.hpp>
#include "type.hpp"
#include "game.hpp"

using asio::ip::udp;

constexpr u16 MAX_LENGTH = 1024;

class Server
{
    public:
        Server(asio::io_context &ioContext, u16 port, Game &game);
        void start();
        void stop();
        void receive();
        void send(const std::string &message, const udp::endpoint &endpoint);

    private:

        asio::io_context &m_ioContext;
        udp::socket m_socket;
        udp::endpoint m_remoteEndpoint;
        u8 m_data[MAX_LENGTH];
        std::thread m_thread;
        Game &m_game;
};