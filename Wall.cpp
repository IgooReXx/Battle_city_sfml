//
// Created by IGOR on 18.06.2023.
//

#include "Wall.h"

CollisionFlag wallCollisions {true, true, false, true};

Wall::Wall() : CollidableObject(wallCollisions, 0, WALL, 32, 32)
{

}

void Wall::take_hit()
{

}
