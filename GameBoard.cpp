//
// Created by IGOR on 17.06.2023.
//

#include "GameBoard.h"
#include "iostream"

#include "./Tanks/AITanks/LightTank.h"
#include "./Tanks/AITanks/MediumTank.h"
#include "./Tanks/AITanks/HeavyTank.h"

GameBoard::GameBoard() : status(RUNNING), player(bullets)
{
    AITank *test = new LightTank(get_bullets(), *this); std::cerr << "Usun potem";
    AITanks.push_back(test);
    test = new MediumTank(get_bullets(), *this);
    AITanks.push_back(test);
    test = new HeavyTank(get_bullets(), *this);
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
    collision_logic();
    for(int indx=0; indx<static_cast<int>(AITanks.size()); indx++)
    {
        AITanks[indx]->update();
    }
    player.update();
    for(int indx=0; indx<static_cast<int>(bullets.size()); indx++)
    {
        bullets[indx]->update();
    }
    bullets_cleanup();
    AITanks_cleanup();
    walls_cleanup();
    check_win_condition();
}

std::vector<Wall*> &GameBoard::get_Walls() {
    return walls;
}


void GameBoard::bullets_cleanup() // Uniknięcie segfaulta https://stackoverflow.com/questions/2037867/can-i-convert-a-reverse-iterator-to-a-forward-iterator
{
    for(auto iter=bullets.rbegin(); iter != bullets.rend(); ++iter)
    {
        if((*iter)->is_destroyed())
        {
            delete *iter;
            bullets.erase((iter+1).base());
        }
    }
}

void GameBoard::AITanks_cleanup() {
    for(auto iter=AITanks.rbegin(); iter != AITanks.rend(); ++iter)
    {
        if((*iter)->is_destroyed())
        {
            delete *iter;
            AITanks.erase((iter+1).base());
        }
    }
}

void GameBoard::walls_cleanup() {
    for(auto iter=walls.rbegin(); iter != walls.rend(); ++iter)
    {
        if((*iter)->is_destroyed())
        {
            delete *iter;
            walls.erase((iter+1).base());
        }
    }
}

void GameBoard::collision_logic()
{
    player_collisions();
    AITanks_collisions();
    bullets_collision();
}

void GameBoard::player_collisions()
{
    for(int indx=0; indx<static_cast<int>(walls.size()); ++indx)
    {
        if(player.check_collision(*walls[indx]))
        {
            player.on_wall_collision();
        }
    }
    if(player.map_boundary_collision())
        player.on_wall_collision();
    for(int indx=0; indx<static_cast<int>(bullets.size()); ++indx)
    {
        if(player.check_collision(*bullets[indx]) and bullets[indx]->get_bulletClass() != PLAYERBULLET)
        {
            bullets[indx]->take_hit();
            player.take_hit();
        }
    }
}

void GameBoard::AITanks_collisions()
{
    for(int AITanksIndx=0; AITanksIndx < static_cast<int>(AITanks.size()); ++AITanksIndx)
    {
        for(int wallsIndx = 0; wallsIndx < static_cast<int>(walls.size()); ++wallsIndx)
        {
            if(AITanks[AITanksIndx]->check_collision(*walls[wallsIndx]))
            {
                AITanks[AITanksIndx]->on_wall_collision();
            }
        }
        if(AITanks[AITanksIndx]->map_boundary_collision())
                AITanks[AITanksIndx]->on_wall_collision();
        for(int bulletsIndx = 0; bulletsIndx < static_cast<int>(bullets.size()); ++bulletsIndx)
        {
            if(AITanks[AITanksIndx]->check_collision(*bullets[bulletsIndx]) and bullets[bulletsIndx]->get_bulletClass() == PLAYERBULLET)
            {
                AITanks[AITanksIndx]->take_hit();
                bullets[bulletsIndx]->take_hit();
            }
        }
    }
}

void GameBoard::bullets_collision()
{
    for(int bulletIndx=0; bulletIndx < static_cast<int>(bullets.size()); ++bulletIndx)
    {
        for(int wallIndx=0; wallIndx < static_cast<int>(walls.size()); ++wallIndx)
        {
            if(bullets[bulletIndx]->check_collision(*walls[wallIndx]))
            {
                bullets[bulletIndx]->take_hit();
                walls[wallIndx]->take_hit();
            }
        }
        if(bullets[bulletIndx]->map_boundary_collision())
        {
            bullets[bulletIndx]->take_hit();
        }
    }
}

void GameBoard::check_win_condition()
{
    if(walls.size() != 0 && walls[0]->is_destroyed())
    {
        status = LOST;
    }
    if(player.is_destroyed())
    {
        status = LOST;
    }
    if(AITanks.size() == 0)
    {
        status = WON;
    }
}

GameStatus GameBoard::get_status() const
{
    return status;
}
