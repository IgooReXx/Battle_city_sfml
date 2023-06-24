//
// Created by IGOR on 17.06.2023.
//

#include "PlayerBullet.h"

static CollisionFlag PlayerBulletCollisions {false, true, true, false};

PlayerBullet::PlayerBullet(Facing facing, sf::Vector2f position, BulletClass bulletClass) : Bullet(PlayerBulletCollisions, facing, position, bulletClass)
{

}
