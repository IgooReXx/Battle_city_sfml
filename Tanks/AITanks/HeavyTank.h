//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_HEAVYTANK_H
#define PLAGIATCITY_HEAVYTANK_H

#include "../AITank.h"

class HeavyTank : public AITank {

public:
    HeavyTank(std::vector<Bullet*> &bullets, GameBoard &b);
};


#endif //PLAGIATCITY_HEAVYTANK_H
