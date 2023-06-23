//
// Created by IGOR on 17.06.2023.
//

#include "HeavyTank.h"

HeavyTank::HeavyTank(std::vector<Bullet*> &bullets, GameBoard &b) : AITank(5, 300, 0.005, HEAVY, bullets, b)
{

}