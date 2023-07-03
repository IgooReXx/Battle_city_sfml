//
// Created by IGOR on 17.06.2023.
//

#include "GameBoard.h"

#include "./Tanks/AITanks/LightTank.h"
#include "./Tanks/AITanks/MediumTank.h"
#include "./Tanks/AITanks/HeavyTank.h"

GameBoard::GameBoard() : status(MENU), player(bullets), bonusHP(nullptr), bonusPickedUp(false)
{
    player.set_position({384, 380});
    spawnCounter=0;
    base = new Base();
    place_walls();
}

PlayerTank &GameBoard::get_Player()
{
    return player;
}

std::vector<Bullet *> &GameBoard::get_bullets()
{
    return bullets;
}

std::vector<AITank*> &GameBoard::get_AITanks()
{
    return AITanks;
}

void GameBoard::update()
{
    spawn_bonusHP();
    spawn_AITanks();
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
    garbage_collector();
    check_win_condition();
}

std::vector<Wall*> &GameBoard::get_Walls()
{
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
    bullets_collisions();
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
    if(player.check_collision(*base))
    {
        player.on_wall_collision();
    }
    if(bonusHP != nullptr)
    {
        if(player.check_collision(*bonusHP))
        {
            delete bonusHP;
            bonusHP = nullptr;
            bonusPickedUp = true;
            player.heal();
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
        if(AITanks[AITanksIndx]->check_collision(*base))
        {
            AITanks[AITanksIndx]->on_wall_collision();
        }
    }
}

void GameBoard::bullets_collisions()
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
        if(bullets[bulletIndx]->check_collision(*base) and bullets[bulletIndx]->get_bulletClass() != PLAYERBULLET)
        {
            bullets[bulletIndx]->take_hit();
            base->take_hit();
        }
    }
}

void GameBoard::check_win_condition()
{
    if(base->is_destroyed())
    {
        status = LOST;
    }
    if(player.is_destroyed())
    {
        status = LOST;
    }
    if(spawnCounter >= 10 and AITanks.empty())
    {
        status = WON;
    }
}

GameStatus GameBoard::get_status() const
{
    return status;
}

void GameBoard::place_big_wall(float x_pos, float y_pos)
{
    place_small_wall(x_pos, y_pos);
    place_small_wall(x_pos+WALL_WIDTH, y_pos);
    place_small_wall(x_pos, y_pos+WALL_HEIGHT);
    place_small_wall(x_pos+WALL_WIDTH, y_pos+WALL_HEIGHT);
}

void GameBoard::place_small_wall(float x_pos, float y_pos)
{
    Wall* tmp = new Wall(REGULAR, {WALL_WIDTH, WALL_HEIGHT});
    tmp->set_position({x_pos, y_pos});
    walls.push_back(tmp);
}

void GameBoard::place_walls()
{
    base->set_position({386, 444});

    place_big_wall(354, 444);
    place_big_wall(385, 412);
    place_big_wall(418, 444);

    place_big_wall(256, 348);
    place_big_wall(288, 348);

    place_big_wall(512, 348);
    place_big_wall(480, 348);

    place_big_wall(256, 156);
    place_big_wall(288, 156);

    place_big_wall(512, 156);
    place_big_wall(480, 156);

}

Wall *GameBoard::get_base() {
    return base;
}

void GameBoard::spawn_AITanks()
{
    AITank* spawnedTank;
    if(spawnTimer.getElapsedTime() >= sf::seconds(10))
    {
        if(spawnCounter < 10)
        {
            switch (spawnCounter)
            {
                case 0:
                case 2:
                case 7:
                    spawnedTank = new LightTank(get_bullets(), *this);
                    break;
                case 1:
                case 3:
                case 4:
                case 9:
                    spawnedTank = new MediumTank(get_bullets(), *this);
                    break;
                case 5:
                case 6:
                case 8:
                    spawnedTank = new HeavyTank(get_bullets(), *this);
                    break;
            }
            if(spawnCounter % 2 == 0)
                spawnedTank->set_position({224, 124});
            else
                spawnedTank->set_position({544, 124});

            AITanks.push_back(spawnedTank);
            spawnCounter++;
            spawnTimer.restart();
        }
    }

}

void GameBoard::garbage_collector()
{
    bullets_cleanup();
    AITanks_cleanup();
    walls_cleanup();
}

void GameBoard::set_status_RUNNING()
{
    status = RUNNING;
}

void GameBoard::spawn_bonusHP()
{
    if(bonusPickedUp)
        return;
    if(bonusHP == nullptr)
    {
        if(player.get_HP() < 5)
        {
            bonusHP = new PickUp();
            bonusHP->set_position({384, 380});
        }
    }
}

PickUp* GameBoard::get_bonusHP()
{
    return bonusHP;
}

bool GameBoard::get_bonusPickedUp() const {
    return bonusPickedUp;
}
