//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_COLLIDABLEOBJECT_H
#define PLAGIATCITY_COLLIDABLEOBJECT_H

#include "MovableObject.h"

#define PA_LEFT 224
#define PA_RIGHT 576
#define PA_TOP 124
#define PA_BOTTOM 476


struct CollisionFlag {
    bool hasPlayerTankCollison;
    bool hasAITankCollision;
    bool hasWallCollision;
    bool hasBulletCollision;
};

class CollidableObject : public MovableObject {

    CollisionFlag objectConfig;

public:

    explicit CollidableObject(CollisionFlag config, float velocity, Type type, float width, float height);
    bool check_collision(const CollidableObject &o) const;
    bool map_boundary_collision() const;

};


#endif //PLAGIATCITY_COLLIDABLEOBJECT_H
