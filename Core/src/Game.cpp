// Game.cpp
#include "Game.hpp"
#include <iostream>

void Game::Load() {
    std::cout << "Game Loaded: " << name << " v" << version << std::endl;
}

void Game::Unload() {
    std::cout << "Game Unloaded" << std::endl;
}
