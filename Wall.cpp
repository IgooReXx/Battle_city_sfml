//
// Created by IGOR on 18.06.2023.
//

#include "Wall.h"

static CollisionFlag wallCollisions {true, true, false, true};

Wall::Wall(WallClass wc, sf::Vector2f size) : CollidableObject(wallCollisions, 0, WALL, size.x, size.y), wallClass(wc)
{

}

void Wall::take_hit()
{
    set_status_destroyed();
}

Wall::~Wall()
{

}

WallClass Wall::get_wallClass() const
{
    return wallClass;
}

