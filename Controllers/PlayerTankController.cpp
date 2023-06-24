//
// Created by IGOR on 24.06.2023.
//

#include "PlayerTankController.h"

PlayerTankController::PlayerTankController(PlayerTank &pT) : playerTank(pT)
{

}

void PlayerTankController::move()
{
    on_movementKeyPressed();
    on_movementKeyReleased();
}

void PlayerTankController::arrow_key_up()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerTank.set_facing(UP);
}

void PlayerTankController::arrow_key_down()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerTank.set_facing(DOWN);
}

void PlayerTankController::arrow_key_left()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerTank.set_facing(LEFT);
}

void PlayerTankController::arrow_key_right()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerTank.set_facing(RIGHT);
}

void PlayerTankController::on_movementKeyPressed()
{
    arrow_key_up();
    arrow_key_down();
    arrow_key_left();
    arrow_key_right();
    playerTank.set_velocity(0.015);
}

void PlayerTankController::on_movementKeyReleased()
{
    bool noMovementInput = ! sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and ! sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and ! sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and ! sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if(noMovementInput)
    {
        playerTank.set_velocity(0);
    }
}

void PlayerTankController::shoot()
{
    spacebar_key();
}

void PlayerTankController::spacebar_key()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        playerTank.shoot();
}
