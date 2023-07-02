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
/// Enum of the game status
enum GameStatus {WON, LOST, RUNNING, MENU};

/// Class handling logic of spawning and collisions of objects during the gameplay
class GameBoard {

    GameStatus status; // status of the current game

    std::vector<Bullet*> bullets; // vector of all bullets on the map

    PlayerTank player;

    std::vector<AITank*> AITanks;   // vector of all AITanks on the map
    sf::Clock spawnTimer;           // clock used in the logic of AI spawning
    int spawnCounter;               // counter used in the logic of AI spawning

    std::vector<Wall*> walls = {}; // vector of all regular walls
    Wall* base;                    // pointer to player's base

    void bullets_cleanup();         //
    void AITanks_cleanup();         // functions handling deletion of unused objects after they've been destroyed
    void walls_cleanup();           //
    void garbage_collector();       //


    void collision_logic();         //
    void player_collisions();       // functions handling collisions and their logic
    void AITanks_collisions();      //
    void bullets_collisions();      //

    void check_win_condition();     // function checking for win/loss conditions

    void place_walls();                                 //
    void place_small_wall(float x_pos, float y_pos);    // functions handling placement of walls on the map
    void place_big_wall(float x_pos, float y_pos);      //

    void spawn_AITanks();           // function spawning AI opponents based on spawnCounter and spawnTimer

public:

    GameBoard();

    // Calls all functions responsible for logic which should happen each update
    void update();

    // Allows to set the gameStatus to RUNNING
    void set_status_RUNNING();

    // Simple getters
    std::vector<Bullet*> &get_bullets();
    PlayerTank &get_Player();
    std::vector<AITank*> &get_AITanks();
    std::vector<Wall*> &get_Walls();
    GameStatus get_status() const;
    Wall* get_base();

};


#endif //PLAGIATCITY_GAMEBOARD_H
