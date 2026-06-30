#include "database.h"

void Database::set(const std::string& key,
                   const std::string& value)
{
    store[key] = value;
}

std::string Database::get(const std::string& key) const
{
    auto it = store.find(key);

    if (it == store.end())
        return "(nil)";

    return it->second;
}

bool Database::del(const std::string& key)
{
    return store.erase(key);
}

bool Database::exists(const std::string& key) const
{
    return store.find(key) != store.end();
}

const std::unordered_map<std::string,
std::string>& Database::getStore() const
{
    return store;
}

void Database::setStore(
    const std::unordered_map<std::string,
    std::string>& newStore)
{
    store = newStore;
}