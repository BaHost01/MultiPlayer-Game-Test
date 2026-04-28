// ShooterService.cpp
#include "ShooterService.hpp"
#include <iostream>

void ShooterService::StartGame() {
    m_health = 100;
    m_ammo = 30;
    m_score = 0;
    std::cout << "Shooter Game Started!" << std::endl;
}

void ShooterService::Shoot() {
    if (m_ammo > 0) {
        m_ammo--;
        std::cout << "Bang! Ammo left: " << m_ammo << std::endl;
    } else {
        std::cout << "Out of ammo! Reload!" << std::endl;
    }
}

void ShooterService::Reload() {
    m_ammo = 30;
    std::cout << "Reloaded." << std::endl;
}
