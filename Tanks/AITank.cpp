//
// Created by IGOR on 17.06.2023.
//

#include "AITank.h"

#include <chrono>
#include <algorithm>
#include <random>
static CollisionFlag AITankCollisions {false, false, true, true};

AITank::AITank(int HP, int reloadTime, float velocity, TankClass tankClass, std::vector<Bullet*> &bullets, GameBoard &b): Tank(AITankCollisions, HP, reloadTime, velocity, AITANK, bullets), board(b), tankClass(tankClass)
{

}

void AITank::on_wall_collision()
{
    set_random_facing();
}

void AITank::AI_logic()
{
    if(movementClock.getElapsedTime() >= sf::milliseconds(1500))
    {
        set_random_facing();
        movementClock.restart();
    }
    if(reloadClock.getElapsedTime() >= sf::milliseconds(get_reloadTime()))
    {
        shoot();
        reloadClock.restart();
    }
}

void AITank::set_random_facing()
{
    static std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::vector<Facing> directions = {UP, DOWN, LEFT, RIGHT};
    shuffle (directions.begin(), directions.end(), engine);

    set_facing(static_cast<Facing>(directions.front()));
}

void AITank::shoot()
{
    bullets.push_back(new AIBullet(get_objectParam().facing, choose_bullet_position(), AIBULLET));
}

sf::Vector2f AITank::choose_bullet_position()
{
    float centreWidth = get_objectParam().object.left+get_objectParam().object.width/2;
    float centreHeight= get_objectParam().object.top+get_objectParam().object.height/2;
    float barrelOffsetWidth = BULLET_WIDTH/2.0f;
    float barrelOffsetHeight = get_objectParam().object.height/2;
    switch (get_objectParam().facing)
    {
        case UP:
            return {centreWidth-barrelOffsetWidth, centreHeight-barrelOffsetHeight};
        case DOWN:
            return {centreWidth-barrelOffsetWidth, centreHeight+barrelOffsetHeight};
        case LEFT:
            return {centreWidth-barrelOffsetHeight, centreHeight-barrelOffsetWidth};
        case RIGHT:
            return {centreWidth+barrelOffsetHeight, centreHeight-barrelOffsetWidth};
    }
    return {-1, -1};
}

TankClass AITank::get_tankClass()
{
    return tankClass;
}

void AITank::update() {
    AI_logic();
    MovableObject::update();
}

