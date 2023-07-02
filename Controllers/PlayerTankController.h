//
// Created by IGOR on 24.06.2023.
//

#ifndef PLAGIATCITY_PLAYERTANKCONTROLLER_H
#define PLAGIATCITY_PLAYERTANKCONTROLLER_H

#include "../Tanks/PlayerTank.h"

class PlayerTankController {

    PlayerTank &playerTank;

    void on_movementKeyPressed();                       // functions handling movement based on keys pressed
    void on_movementKeyReleased();

    void arrow_key_up();                                // functions which set player tank's parameters on specific key press
    void arrow_key_down();
    void arrow_key_left();
    void arrow_key_right();
    void spacebar_key();

public:
    explicit PlayerTankController(PlayerTank &pT);
    void move();                                        // function allowing player to move the tank
    void shoot();                                       // function allowing player to shoot


};


#endif //PLAGIATCITY_PLAYERTANKCONTROLLER_H
