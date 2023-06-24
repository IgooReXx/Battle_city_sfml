//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_BULLET_H
#define PLAGIATCITY_BULLET_H

#include "../Objects/CollidableObject.h"
#include "../Wall.h"

#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8

enum BulletClass {AIBULLET, PLAYERBULLET};

class Bullet : public CollidableObject {
    BulletClass bulletClass;
    void hitObject(CollidableObject object) const;
    bool check_wall_collison(std::vector<Wall>& walls);

public:

    Bullet(CollisionFlag bulletCollisions, Facing facing, sf::Vector2f position, BulletClass bulletClass);
    virtual ~Bullet();
    void take_hit() override;
    BulletClass get_bulletClass();
};


#endif //PLAGIATCITY_BULLET_H
