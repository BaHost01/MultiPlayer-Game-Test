// ShooterService.hpp
#pragma once
#include <string>

class ShooterService {
public:
    void StartGame();
    void Shoot();
    void Reload();

    int GetHealth() const { return m_health; }
    int GetAmmo() const { return m_ammo; }
    int GetScore() const { return m_score; }

private:
    int m_health = 100;
    int m_ammo = 30;
    int m_score = 0;
};
