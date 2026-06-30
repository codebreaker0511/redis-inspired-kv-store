#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <unordered_map>

class Database
{
private:

    std::unordered_map<std::string, std::string> store;

public:

    Database() = default;

    void set(const std::string& key,
             const std::string& value);

    std::string get(const std::string& key) const;

    bool del(const std::string& key);

    bool exists(const std::string& key) const;

    const std::unordered_map<std::string, std::string>&
    getStore() const;

    void setStore(
        const std::unordered_map<std::string,
        std::string>& newStore);
};

#endif