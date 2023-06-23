//
// Created by IGOR on 17.06.2023.
//

#include "AIBullet.h"

CollisionFlag AIBulletCollisions {true, false, true, false};

AIBullet::AIBullet(Facing facing, sf::Vector2f position) : Bullet(AIBulletCollisions, facing, position)
{

}
