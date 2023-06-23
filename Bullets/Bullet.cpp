//
// Created by IGOR on 16.06.2023.
//

#include "Bullet.h"

Bullet::Bullet(CollisionFlag bulletCollisions, Facing facing, sf::Vector2f position) :
CollidableObject{bulletCollisions, 0.04, BULLET, BULLET_WIDTH, BULLET_HEIGHT}
{
    set_facing(facing);
    set_position(position);
}

void Bullet::hitObject(CollidableObject object) const
{
    object.take_hit();
}

void Bullet::take_hit()
{
    set_status_destroyed();
}

void Bullet::check_wall_collison()
{
    //for(int indx=0; indx<static_cast<int>(board.get_Walls().size()); indx++)
    //    {
    //        if(check_collision(board.get_Walls()[indx]))
    //            return true;
    //    }
    //    return false;
}



