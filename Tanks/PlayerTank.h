//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_PLAYERTANK_H
#define PLAGIATCITY_PLAYERTANK_H

#include "Tank.h"


class PlayerTank : public Tank{

public:
    explicit PlayerTank(std::vector<Bullet*> &bullets);
    void update() override;
};


#endif //PLAGIATCITY_PLAYERTANK_H
