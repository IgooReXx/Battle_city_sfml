//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_PLAYERBULLET_H
#define PLAGIATCITY_PLAYERBULLET_H

#include "Bullet.h"

class PlayerBullet : public Bullet{

public:
    PlayerBullet(Facing facing, sf::Vector2f position, BulletClass bulletClass);
};


#endif //PLAGIATCITY_PLAYERBULLET_H
