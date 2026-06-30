#include <iostream>

#include "database.h"
#include "commands.h"
#include "server.h"

int main()
{
    Database database;

    CommandHandler handler(database);

    Server server(6379, handler);

    if (!server.start())
    {
        std::cout << "Server Startup Failed" << std::endl;
        return 1;
    }

    server.run();

    server.stop();

    return 0;
}