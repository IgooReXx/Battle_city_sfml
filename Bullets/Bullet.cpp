//
// Created by IGOR on 16.06.2023.
//

#include "Bullet.h"

Bullet::Bullet(CollisionFlag bulletCollisions, Facing facing, sf::Vector2f position, BulletClass bulletClass) :
CollidableObject{bulletCollisions, 1.5, BULLET, BULLET_WIDTH, BULLET_HEIGHT}, bulletClass(bulletClass)
{
    set_facing(facing);
    set_position(position);
}

void Bullet::take_hit()
{
    set_status_destroyed();
}

Bullet::~Bullet()
{

}

BulletClass Bullet::get_bulletClass() const
{
    return bulletClass;
}
