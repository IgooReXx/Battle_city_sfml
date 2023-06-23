//
// Created by IGOR on 17.06.2023.
//

#include "PlayerTank.h"
CollisionFlag playerTankCollisions {false, false, true, true};

PlayerTank::PlayerTank(std::vector<Bullet*> &bullets) : Tank(playerTankCollisions, 20, 200, 0.015, PLAYERTANK, bullets)
{

}

void PlayerTank::update() {
    MovableObject::update();
    shoot();
}
