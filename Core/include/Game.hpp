// Game.hpp
#pragma once
#include <string>

class Game {
public:
    std::string name    = "MyGame";
    int         version = 1;

    void Load();
    void Unload();
};
