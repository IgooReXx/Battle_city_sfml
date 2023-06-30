//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_AITANK_H
#define PLAGIATCITY_AITANK_H
class AITank; // Loop include'ów rozwiązany z pomocą kolegi
#include "Tank.h"
#include "../GameBoard.h"
#include <SFML/System/Clock.hpp>

/// Enum used for differentiating AITanks
enum TankClass {LIGHT, MEDIUM, HEAVY};

/// Parent class for LightTank, MediumTank, HeavyTank
class AITank : public Tank {

    GameBoard &board;

    TankClass tankClass;
    sf::Clock movementClock; // clock used for random AI movement
    sf::Clock reloadClock;   // clock used for checking whether AI should fire another shot
    void AI_logic();         // function handles AI movement and firing logic using above-mentioned clocks and two functions visible below
    void set_random_facing();
    void shoot() override;

    sf::Vector2f choose_bullet_position() const; // function used for setting a newly shot bullet's position based on current tank position and facing

public:
    AITank(int HP, int reloadTime, float velocity, TankClass tankClass, std::vector<Bullet*> &bullets, GameBoard &b);
    TankClass get_tankClass() const;
    void update() override;
    void on_wall_collision();
};


#endif //PLAGIATCITY_AITANK_H
