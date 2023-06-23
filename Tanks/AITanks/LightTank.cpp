//
// Created by IGOR on 17.06.2023.
//

#include "LightTank.h"

LightTank::LightTank(std::vector<Bullet*> &bullets, GameBoard &b) : AITank(1, 450, 0.02, LIGHT, bullets, b)
{

}