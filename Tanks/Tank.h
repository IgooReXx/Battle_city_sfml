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

/// Parent class for AITank and PlayerTank

class Tank : public CollidableObject {

    int healthPoints;
    int reloadTime;

protected:

    std::vector<Bullet*> &bullets;

public:

    Tank(CollisionFlag config, int HP, int reloadTime, float velocity, Type type, std::vector<Bullet*> &b);

    virtual ~Tank();

    virtual void shoot(); // Function allows tanks to shoot a bullet

    virtual void on_wall_collision();

    void take_hit() override;
    void heal();

    // Simple getters
    int get_reloadTime() const;
    int get_HP() const; // HP - healthPoints
};


#endif //PLAGIATCITY_TANK_H
