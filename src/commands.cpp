#include "commands.h"

CommandHandler::CommandHandler(Database& db)
    : database(db),
      persistence(db)
{
}

std::string CommandHandler::execute(
    const std::vector<std::string>& tokens)
{
    if (tokens.empty())
        return "Empty Command";

    std::string command = tokens[0];

    if (command == "SET")
    {
        if (tokens.size() != 3)
            return "Usage: SET <key> <value>";

        database.set(tokens[1], tokens[2]);

        return "OK";
    }

    if (command == "GET")
    {
        if (tokens.size() != 2)
            return "Usage: GET <key>";

        return database.get(tokens[1]);
    }

    if (command == "DEL")
    {
        if (tokens.size() != 2)
            return "Usage: DEL <key>";

        return database.del(tokens[1]) ? "1" : "0";
    }

    if (command == "EXISTS")
    {
        if (tokens.size() != 2)
            return "Usage: EXISTS <key>";

        return database.exists(tokens[1]) ? "1" : "0";
    }

    if (command == "SAVE")
    {
        return persistence.save()
            ? "Database Saved"
            : "Save Failed";
    }

    if (command == "LOAD")
    {
        return persistence.load()
            ? "Database Loaded"
            : "Load Failed";
    }

    return "Unknown Command";
}