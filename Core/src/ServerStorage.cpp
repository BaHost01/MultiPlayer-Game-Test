// ServerStorage.cpp
#include "ServerStorage.hpp"

void ServerStorage::Set(const std::string& key, std::any value) {
    m_data[key] = value;
}

std::any ServerStorage::Get(const std::string& key) const {
    auto it = m_data.find(key);
    if (it != m_data.end()) return it->second;
    return {};
}

bool ServerStorage::Has(const std::string& key) const {
    return m_data.find(key) != m_data.end();
}
