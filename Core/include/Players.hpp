// Players.hpp
#pragma once
#include <vector>
#include <string>

struct Player {
    std::string name;
    int         userId;
    float       x, y, z;   // position
};

class Players {
public:
    void                     AddPlayer(const std::string& name, int id = 0);
    void                     RemovePlayer(int id);
    Player*                  GetPlayerById(int id);
    const std::vector<Player>& GetAll() const { return m_players; }

private:
    std::vector<Player> m_players;
    int                 m_nextId = 1;
};
