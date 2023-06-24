//
// Created by IGOR on 18.06.2023.
//

#ifndef PLAGIATCITY_WALL_H
#define PLAGIATCITY_WALL_H

#include "./Objects/CollidableObject.h"

class Wall : public CollidableObject {

public:
    Wall();
    virtual ~Wall();
    void take_hit() override;
};


#endif //PLAGIATCITY_WALL_H
