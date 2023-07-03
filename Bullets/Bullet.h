//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_BULLET_H
#define PLAGIATCITY_BULLET_H

#include "../Objects/CollidableObject.h"
#include "../Walls/Wall.h"

#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8
/// Enum used to differentiate bullets shot by player from bullets shot by AI opponent
enum BulletClass {AIBULLET, PLAYERBULLET};

/// Parent class to AIBullet and PlayerBullet
class Bullet : public CollidableObject {
    BulletClass bulletClass;

public:

    Bullet(CollisionFlag bulletCollisions, Facing facing, sf::Vector2f position, BulletClass bulletClass);

    virtual ~Bullet();

    void take_hit() override;

    // Simple getter
    BulletClass get_bulletClass() const;
};


#endif //PLAGIATCITY_BULLET_H
