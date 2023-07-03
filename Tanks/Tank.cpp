//
// Created by IGOR on 17.06.2023.
//

#include "Tank.h"


Tank::Tank(CollisionFlag config, int HP, int reloadTime, float v, Type t, std::vector<Bullet*> &b) :
CollidableObject( config, v, t, TANK_WIDTH, TANK_HEIGHT), healthPoints(HP), reloadTime(reloadTime), bullets(b)
{

}

void Tank::shoot()
{

}

void Tank::take_hit()
{
    if(healthPoints > 1)
        healthPoints-=1;
    else
        set_status_destroyed();
}

int Tank::get_reloadTime() const {
    return reloadTime;
}

Tank::~Tank()
{

}

int Tank::get_HP() const {
    return healthPoints;
}

void Tank::on_wall_collision()
{

}

void Tank::heal()
{
    healthPoints++;
}


