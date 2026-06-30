#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

#include "database.h"

class Persistence
{
private:

    Database& database;

    std::string filename;

public:

    Persistence(Database& db,
                const std::string& file = "data/dump.rdb");

    bool save();

    bool load();
};

#endif