//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_TANK_H
#define PLAGIATCITY_TANK_H

class Tank;

#include "../Objects/CollidableObject.h"
#include "../Bullets/Bullet.h"

#define TANK_WIDTH 30
#define TANK_HEIGHT 30

class Tank : public CollidableObject {

    int healthPoints;
    int reloadTime;

protected:

    std::vector<Bullet*> &bullets;

public:

    Tank(CollisionFlag config, int HP, int reloadTime, float velocity, Type type, std::vector<Bullet*> &b);
    virtual ~Tank();
    virtual void shoot();
    void take_hit() override;
    int get_reloadTime() const;
    int get_HP() const;
};


#endif //PLAGIATCITY_TANK_H
