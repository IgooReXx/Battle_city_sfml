//
// Created by IGOR on 16.06.2023.
//

#include "CollidableObject.h"

CollidableObject::CollidableObject(CollisionFlag config, float v, Type t, float w, float h) : MovableObject(v, t, w, h), objectConfig{config}
{
}

bool CollidableObject::check_collision(const CollidableObject &o) const
{

    switch (o.get_objectParam().type)
    {
        case PLAYERTANK:
            if(!this->objectConfig.hasPlayerTankCollison) return false;
            break;
        case AITANK:
            if(!this->objectConfig.hasAITankCollision) return false;
            break;
        case WALL:
            if(!this->objectConfig.hasWallCollision) return false;
            break;
        case BULLET:
            if(!this->objectConfig.hasBulletCollision) return false;
            break;
    }
    return this->get_next_objectParam().object.intersects(o.get_next_objectParam().object);

}

bool CollidableObject::map_boundary_collision() const {

    if(get_next_objectParam().object.left < 0)
        return true;
    if(get_next_objectParam().object.left+get_next_objectParam().object.width > MAP_WIDTH)
        return true;
    if(get_next_objectParam().object.top < 0)
        return true;
    if(get_next_objectParam().object.top+get_next_objectParam().object.height > MAP_HEIGHT)
        return true;

    return false;
}


