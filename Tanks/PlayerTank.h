//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_PLAYERTANK_H
#define PLAGIATCITY_PLAYERTANK_H
#include <SFML/System/Clock.hpp>
class PlayerTank;
#include "Tank.h"


class PlayerTank : public Tank{

    sf::Clock reloadClock; // used for determining whether the player can shoot another bullet

    sf::Vector2f choose_bullet_position() const; // function used for setting a newly shot bullet's position based on current tank position and facing

public:

    explicit PlayerTank(std::vector<Bullet*> &bullets);

    void update() override;

    void on_wall_collision() override;

    void shoot() override;


};


#endif //PLAGIATCITY_PLAYERTANK_H
