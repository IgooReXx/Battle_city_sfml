//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_AITANK_H
#define PLAGIATCITY_AITANK_H
class AITank; // Loop include'ów rozwiązany z pomocą kolegi
#include "Tank.h"
#include "../GameBoard.h"
#include <SFML/System/Clock.hpp>


enum TankClass {LIGHT, MEDIUM, HEAVY};

class AITank : public Tank {

    GameBoard &board;

    TankClass tankClass;
    sf::Clock movementClock;
    sf::Clock reloadClock;
    void AI_logic();
    void set_random_facing();
    void shoot() override;

    sf::Vector2f choose_bullet_position() const;

public:
    AITank(int HP, int reloadTime, float velocity, TankClass tankClass, std::vector<Bullet*> &bullets, GameBoard &b);
    TankClass get_tankClass() const;
    void update() override;
    void on_wall_collision();
};


#endif //PLAGIATCITY_AITANK_H
