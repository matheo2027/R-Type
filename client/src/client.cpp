#include "client.hpp"

Client::Client(asio::io_context &ioContext, const std::string &address, u16 port)
    : m_ioContext(ioContext), 
      m_socket(ioContext, udp::endpoint(udp::v4(), 0)),
      m_remoteEndpoint(asio::ip::address::from_string(address), port)
{
    receive();
}

void Client::receive()
{
    m_socket.async_receive_from(asio::buffer(m_data, MAX_LENGTH), m_remoteEndpoint,
        [this](std::error_code error, usize bytesReceived)
        {
            if (!error && bytesReceived > 0) {
                std::string message(reinterpret_cast<char*>(m_data), bytesReceived);
                std::cout << "Received: " << message << std::endl;
                receive();
            }
        }
    );
}

void Client::send(const std::string &message)
{
    m_socket.async_send_to(asio::buffer(message), m_remoteEndpoint,
        [this, message](std::error_code error, usize bytesSent)
        {
            if (error && bytesSent < 0) {
                std::cerr << "Error: " << error.message() << std::endl;
            }
        }
    );
}

void Client::start()
{
    std::thread ioThread([this]() { m_ioContext.run(); });

    std::string message;
    while (true)
    {
        std::getline(std::cin, message);
        if (message == "exit") {
            send("exit");
            break;
        }
        send(message);
    }

    m_ioContext.stop();
    ioThread.join();
}
    