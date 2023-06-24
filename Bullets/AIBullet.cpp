//
// Created by IGOR on 17.06.2023.
//

#include "AIBullet.h"

static CollisionFlag AIBulletCollisions {true, false, true, false};

AIBullet::AIBullet(Facing facing, sf::Vector2f position, BulletClass bulletClass) : Bullet(AIBulletCollisions, facing, position, bulletClass)
{

}
