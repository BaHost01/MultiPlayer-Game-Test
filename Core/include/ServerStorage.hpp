// ServerStorage.hpp
#pragma once
#include <unordered_map>
#include <string>
#include <any>

class ServerStorage {
public:
    void        Set(const std::string& key, std::any value);
    std::any    Get(const std::string& key) const;
    bool        Has(const std::string& key) const;

private:
    std::unordered_map<std::string, std::any> m_data;
};
