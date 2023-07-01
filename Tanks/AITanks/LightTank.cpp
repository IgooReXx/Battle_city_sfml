//
// Created by IGOR on 17.06.2023.
//

#include "LightTank.h"

LightTank::LightTank(std::vector<Bullet*> &bullets, GameBoard &b) : AITank(1, 700, 0.8, LIGHT, bullets, b)
{

}