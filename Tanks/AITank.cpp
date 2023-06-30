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
    sf::Vector2f position;
    switch(get_objectParam().facing)
    {
        case UP:
            position = {get_objectParam().object.left, get_objectParam().object.top + get_objectParam().velocity};
            break;
        case LEFT:
            position = {get_objectParam().object.left + get_objectParam().velocity, get_objectParam().object.top};
            break;
        case RIGHT:
            position = {get_objectParam().object.left - get_objectParam().velocity, get_objectParam().object.top};
            break;
        case DOWN:
            position = {get_objectParam().object.left, get_objectParam().object.top - get_objectParam().velocity};
            break;
    }
    set_position(position);
    set_random_facing();
}

void AITank::AI_logic()
{
    if(movementClock.getElapsedTime() >= sf::milliseconds(rand()%3000+1500)) // Check whether AI should do a turn
    {
        set_random_facing();
        movementClock.restart();
    }
    if(reloadClock.getElapsedTime() >= sf::milliseconds(get_reloadTime())) // Check whether AI can shoot
    {
        shoot();
        reloadClock.restart();
    }
}

// https://cplusplus.com/reference/algorithm/shuffle/
void AITank::set_random_facing() // Randomly chooses a direction for AI
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

sf::Vector2f AITank::choose_bullet_position() const
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

TankClass AITank::get_tankClass() const
{
    return tankClass;
}

void AITank::update()
{
    AI_logic();
    MovableObject::update();
}

