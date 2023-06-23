//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_LIGHTTANK_H
#define PLAGIATCITY_LIGHTTANK_H

#include "../AITank.h"

class LightTank : public AITank {

public:
    LightTank(std::vector<Bullet*> &bullets, GameBoard &b);
};


#endif //PLAGIATCITY_LIGHTTANK_H
