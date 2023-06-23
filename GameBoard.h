//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_GAMEBOARD_H
#define PLAGIATCITY_GAMEBOARD_H

class GameBoard; // Loop include'ów rozwiązany z pomocą kolegi
#include <vector>

#include "./Tanks/PlayerTank.h"

#include "./Tanks/AITank.h"

#include "./Bullets/AIBullet.h"
#include "./Bullets/PlayerBullet.h"

#include "Wall.h"

class GameBoard {

    std::vector<Bullet*> bullets;
    PlayerTank player;
    std::vector<AITank*> AITanks;
    std::vector<Wall> walls = {};

public:
    GameBoard();
    void update();
    std::vector<Bullet*> &get_bullets();
    PlayerTank &get_Player();
    std::vector<AITank*> &get_AITanks();
    std::vector<Wall> &get_Walls();
};


#endif //PLAGIATCITY_GAMEBOARD_H
