//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_MEDIUMTANK_H
#define PLAGIATCITY_MEDIUMTANK_H

#include "../AITank.h"

class MediumTank : public AITank {
public:
    MediumTank(std::vector<Bullet*> &bullets, GameBoard &b);
};


#endif //PLAGIATCITY_MEDIUMTANK_H
