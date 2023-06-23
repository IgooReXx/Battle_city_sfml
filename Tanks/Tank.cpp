//
// Created by IGOR on 17.06.2023.
//

#include "Tank.h"


Tank::Tank(CollisionFlag config, int HP, int reloadTime, float v, Type t, std::vector<Bullet*> &b) :
CollidableObject( config, v, t, TANK_WIDTH, TANK_HEIGHT), healthPoints(HP), reloadTime(reloadTime), bullets(b)
{

}

void Tank::move(Facing f)
{
    if(f != get_objectParam().facing)
        set_facing(f);
    else
        update();
}

void Tank::shoot()
{

}

void Tank::take_hit()
{
    if(healthPoints > 0)
        healthPoints-=1;
}

bool Tank::is_alive() const
{
    return healthPoints > 0;
}

int Tank::get_reloadTime() const {
    return reloadTime;
}


