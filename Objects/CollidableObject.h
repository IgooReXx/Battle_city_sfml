//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_COLLIDABLEOBJECT_H
#define PLAGIATCITY_COLLIDABLEOBJECT_H

#include "MovableObject.h"

// PA - Playable Area
#define PA_LEFT 224
#define PA_RIGHT 576
#define PA_TOP 124
#define PA_BOTTOM 476

/// Struct used for setting each objects collision flags
struct CollisionFlag {
    bool hasPlayerTankCollison;
    bool hasAITankCollision;
    bool hasWallCollision;
    bool hasBulletCollision;
};
/// Class handling collision with other objects
class CollidableObject : public MovableObject {

    CollisionFlag objectConfig;

public:

    explicit CollidableObject(CollisionFlag config, float velocity, Type type, float width, float height);
    bool check_collision(const CollidableObject &o) const; // function allows to check whether object will collide with object o after an update
    bool map_boundary_collision() const;                   // function allows to check whether objet will collide with playable area after an update
                                                           // both functions return true if collision occurs, they return false otherwise
};


#endif //PLAGIATCITY_COLLIDABLEOBJECT_H
