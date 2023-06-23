//
// Created by IGOR on 17.06.2023.
//

#include "GameBoard.h"
#include "iostream"

#include "./Tanks/AITanks/LightTank.h"
#include "./Tanks/AITanks/MediumTank.h"
#include "./Tanks/AITanks/HeavyTank.h"

GameBoard::GameBoard() : player(bullets)
{
    AITank *test = new LightTank(get_bullets(), *this); std::cerr << "Usun potem";
    AITanks.push_back(test);
}

PlayerTank &GameBoard::get_Player() {
    return player;
}

std::vector<Bullet *> &GameBoard::get_bullets() {
    return bullets;
}

std::vector<AITank*> &GameBoard::get_AITanks()
{
    return AITanks;
}

void GameBoard::update()
{
    for(int indx=0; indx<static_cast<int>(AITanks.size()); indx++)
    {
        AITanks[indx]->update();
    }
    player.update();
    for(int indx=0; indx<static_cast<int>(bullets.size()); indx++)
    {
        bullets[indx]->update();
    }
}

std::vector<Wall> &GameBoard::get_Walls() {
    return walls;
}
