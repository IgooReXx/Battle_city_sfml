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
#include "Base.h"

enum GameStatus {WON, LOST, RUNNING, MENU};

class GameBoard {

    GameStatus status;

    std::vector<Bullet*> bullets;
    PlayerTank player;
    std::vector<AITank*> AITanks;
    sf::Clock spawnTimer;
    int spawnCounter;
    std::vector<Wall*> walls = {};
    Wall* base;

    void bullets_cleanup();
    void AITanks_cleanup();
    void walls_cleanup();
    void garbage_collector();


    void collision_logic();
    void player_collisions();
    void AITanks_collisions();
    void bullets_collision();

    void check_win_condition();

    void place_walls();
    void spawn_AITanks();

public:
    GameBoard();
    void update();
    std::vector<Bullet*> &get_bullets();
    PlayerTank &get_Player();
    std::vector<AITank*> &get_AITanks();
    std::vector<Wall*> &get_Walls();
    GameStatus get_status() const;
    Wall* get_base();
    void set_status_RUNNING();
};


#endif //PLAGIATCITY_GAMEBOARD_H
