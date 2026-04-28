// Players.cpp
#include "Players.hpp"
#include <algorithm>

void Players::AddPlayer(const std::string& name, int id) {
    int actualId = (id == 0) ? m_nextId++ : id;
    m_players.push_back({name, actualId, 0.0f, 0.0f, 0.0f});
}

void Players::RemovePlayer(int id) {
    m_players.erase(std::remove_if(m_players.begin(), m_players.end(),
        [id](const Player& p) { return p.userId == id; }), m_players.end());
}

Player* Players::GetPlayerById(int id) {
    for (auto& p : m_players) {
        if (p.userId == id) return &p;
    }
    return nullptr;
}
