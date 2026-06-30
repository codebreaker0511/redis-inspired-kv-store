#include "server.h"

#include <iostream>
#include <cstring>

Server::Server(int port, CommandHandler& handler)
    : port(port),
      handler(handler)
{
    serverSocket = INVALID_SOCKET;
}

bool Server::start()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "WSAStartup Failed\n";
        return false;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (serverSocket == INVALID_SOCKET)
    {
        std::cout << "Socket Creation Failed\n";
        WSACleanup();
        return false;
    }

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket,
             reinterpret_cast<sockaddr*>(&serverAddr),
             sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cout << "Bind Failed\n";

        closesocket(serverSocket);
        WSACleanup();

        return false;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "Listen Failed\n";

        closesocket(serverSocket);
        WSACleanup();

        return false;
    }

    std::cout << "Redis Inspired Server Listening on Port "
              << port
              << std::endl;

    return true;
}

void Server::run()
{
    while (true)
    {
        SOCKET clientSocket =
            accept(serverSocket,
                   nullptr,
                   nullptr);

        if (clientSocket == INVALID_SOCKET)
            continue;

        std::cout << "Client Connected" << std::endl;

        char buffer[4096];

        while (true)
        {
            memset(buffer, 0, sizeof(buffer));

            int bytesReceived =
                recv(clientSocket,
                     buffer,
                     sizeof(buffer) - 1,
                     0);

            if (bytesReceived <= 0)
            {
                break;
            }

            std::string input(buffer);

            while (!input.empty() &&
                  (input.back() == '\n' ||
                   input.back() == '\r'))
            {
                input.pop_back();
            }

            auto tokens = parser.parse(input);

            std::string response =
                handler.execute(tokens);

            response += "\r\n";

            send(clientSocket,
                 response.c_str(),
                 static_cast<int>(response.size()),
                 0);
        }

        closesocket(clientSocket);

        std::cout
            << "Client Disconnected"
            << std::endl;
    }
}

void Server::stop()
{
    if (serverSocket != INVALID_SOCKET)
        closesocket(serverSocket);

    WSACleanup();
}