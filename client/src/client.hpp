#pragma once

#include <asio.hpp>
#include <iostream>
#include "type.hpp"

using asio::ip::udp;

constexpr u16 MAX_LENGTH = 1024;

class Client
{
    public:
        Client(asio::io_context &ioContext, const std::string &address, u16 port);

        void receive();
        void send(const std::string &message);

        void start();

    private:
        asio::io_context &m_ioContext;
        udp::socket m_socket;
        udp::endpoint m_remoteEndpoint;
        u8 m_data[MAX_LENGTH];
};