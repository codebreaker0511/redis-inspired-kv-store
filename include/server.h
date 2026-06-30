#ifndef SERVER_H
#define SERVER_H

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>

#include <string>

#include "parser.h"
#include "commands.h"

class Server
{
private:

    SOCKET serverSocket;

    int port;

    Parser parser;

    CommandHandler& handler;

public:

    Server(int port, CommandHandler& handler);

    bool start();

    void run();

    void stop();
};

#endif