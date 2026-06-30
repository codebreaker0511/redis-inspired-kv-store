#include "persistence.h"

#include <fstream>
#include <iostream>
#include <unordered_map>

Persistence::Persistence(Database& db,
                         const std::string& file)
    : database(db),
      filename(file)
{
}

bool Persistence::save()
{
    std::ofstream out(filename);

    if (!out.is_open())
        return false;

    const auto& store = database.getStore();

    for (const auto& pair : store)
    {
        out << pair.first
            << "="
            << pair.second
            << "\n";
    }

    out.close();

    return true;
}

bool Persistence::load()
{
    std::ifstream in(filename);

    if (!in.is_open())
        return false;

    std::unordered_map<std::string, std::string> temp;

    std::string line;

    while (getline(in, line))
    {
        size_t pos = line.find('=');

        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);

        std::string value = line.substr(pos + 1);

        temp[key] = value;
    }

    database.setStore(temp);

    in.close();

    return true;
}