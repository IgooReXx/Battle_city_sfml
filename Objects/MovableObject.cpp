//
// Created by IGOR on 16.06.2023.
//

#include "MovableObject.h"

MovableObject::MovableObject(float v, Type t, float width, float height)
{
    objectParam.object = {0, 0, width, height};
    objectParam.velocity = v;
    objectParam.facing = RIGHT;
    objectParam.type = t;
    objectParam.status=ALIVE;
}

void MovableObject::update()
{
    switch(objectParam.facing)
    {
        case UP:
            objectParam.object.top-=objectParam.velocity;
            break;
        case LEFT:
            objectParam.object.left-=objectParam.velocity;
            break;
        case RIGHT:
            objectParam.object.left+=objectParam.velocity;
            break;
        case DOWN:
            objectParam.object.top+=objectParam.velocity;
            break;
    }
}

mvObject MovableObject::get_objectParam() const
{
    return objectParam;
}

void MovableObject::set_facing(Facing f)
{
    objectParam.facing = f;
}

void MovableObject::set_velocity(float v)
{
    objectParam.velocity = v;
}

mvObject MovableObject::get_next_objectParam() const {

    mvObject nextObjectParam = objectParam;

    switch(nextObjectParam.facing)
    {
        case UP:
            nextObjectParam.object.top-=nextObjectParam.velocity;
            break;
        case LEFT:
            nextObjectParam.object.left-=nextObjectParam.velocity;
            break;
        case RIGHT:
            nextObjectParam.object.left+=nextObjectParam.velocity;
            break;
        case DOWN:
            nextObjectParam.object.top+=nextObjectParam.velocity;
            break;
    }

    return nextObjectParam;

}

void MovableObject::take_hit()
{

}

void MovableObject::set_position(sf::Vector2f position)
{
    objectParam.object.left = position.x;
    objectParam.object.top = position.y;
}

void MovableObject::set_status_destroyed()
{
    objectParam.status = DESTROYED;
}

bool MovableObject::is_destroyed() const
{
    return (objectParam.status == DESTROYED);
}

