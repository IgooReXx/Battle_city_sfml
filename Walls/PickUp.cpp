//
// Created by IGOR on 03.07.2023.
//

#include "PickUp.h"

static CollisionFlag pickUpCollisions {true, false, false, false};

PickUp::PickUp() : CollidableObject(pickUpCollisions, 0, WALL, 32, 32)
{

}

PickUp::~PickUp()
{

}


