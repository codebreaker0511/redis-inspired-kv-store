#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>

#include "database.h"
#include "persistence.h"

class CommandHandler
{
private:

    Database& database;

    Persistence persistence;

public:

    CommandHandler(Database& db);

    std::string execute(
        const std::vector<std::string>& tokens
    );
};

#endif