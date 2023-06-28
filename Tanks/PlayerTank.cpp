//
// Created by IGOR on 17.06.2023.
//

#include "PlayerTank.h"
#include "../Bullets/PlayerBullet.h"

static CollisionFlag playerTankCollisions {false, false, true, true};

PlayerTank::PlayerTank(std::vector<Bullet*> &bullets) : Tank(playerTankCollisions, 20, 500, 0, PLAYERTANK, bullets)
{

}

void PlayerTank::update() {
    MovableObject::update();
}

void PlayerTank::on_wall_collision()
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
}

void PlayerTank::shoot()
{
    if(reloadClock.getElapsedTime() >= sf::milliseconds(get_reloadTime()))
    {
        sf::Vector2f position = choose_bullet_position();
        bullets.push_back(new PlayerBullet(get_objectParam().facing, {position.x, position.y}, PLAYERBULLET));
        reloadClock.restart();
    }
}

sf::Vector2f PlayerTank::choose_bullet_position() const
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