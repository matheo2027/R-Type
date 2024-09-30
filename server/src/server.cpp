#include "server.hpp"

Server::Server(asio::io_context &ioContext, u16 port, Game &game)
    : m_ioContext(ioContext),
      m_socket(ioContext, udp::endpoint(udp::v4(), port)),
      m_game(game)
{
    receive();
}

void Server::start()
{
    m_thread = std::thread([this]
    {
        m_ioContext.run();
    });
}

void Server::stop()
{
    m_ioContext.stop();
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void Server::receive()
{
    m_socket.async_receive_from(asio::buffer(m_data, MAX_LENGTH), m_remoteEndpoint,
        [this](std::error_code error, usize bytesReceived)
        {
            if (!error && bytesReceived > 0) {
                std::string message(reinterpret_cast<char *>(m_data), bytesReceived);
                m_game.addPlayer(m_remoteEndpoint);
                m_game.handleMessage(message, m_remoteEndpoint);
            }
            receive();
        }
    );
}

void Server::send(const std::string &message, const udp::endpoint &endpoint)
{
    m_socket.async_send_to(asio::buffer(message), endpoint,
        [this, message](std::error_code error, usize bytesSent)
        {
            if (!error && bytesSent > 0) {
                std::cout << "Sent: " << message << std::endl;
            } else {
                std::cerr << "Error sending message: " << error.message() << std::endl;
            }
        }
    );
}
