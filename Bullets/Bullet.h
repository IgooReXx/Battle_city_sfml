//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_BULLET_H
#define PLAGIATCITY_BULLET_H

#include "../Objects/CollidableObject.h"

#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8

class Bullet : public CollidableObject {
    void hitObject(CollidableObject object) const;
    void take_hit() override;
    void check_wall_collison();

public:

    explicit Bullet(CollisionFlag bulletCollisions, Facing facing, sf::Vector2f position);

};


#endif //PLAGIATCITY_BULLET_H
