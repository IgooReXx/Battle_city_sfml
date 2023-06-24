//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_AIBULLET_H
#define PLAGIATCITY_AIBULLET_H

#include "Bullet.h"

class AIBullet : public Bullet {

public:
    AIBullet(Facing facing, sf::Vector2f position, BulletClass bulletClass);
};


#endif //PLAGIATCITY_AIBULLET_H
