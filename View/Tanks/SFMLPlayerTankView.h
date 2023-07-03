//
// Created by IGOR on 23.06.2023.
//

#ifndef PLAGIATCITY_SFMLPLAYERTANKVIEW_H
#define PLAGIATCITY_SFMLPLAYERTANKVIEW_H

#include "../../Tanks/PlayerTank.h"
#include "../../GameBoard.h"
#include "../TxSp.h"

class SFMLPlayerTankView {
    GameBoard &board;

    PlayerTank &playerTank;
    TxSp playerTankModel;

    sf::RenderWindow &win;

    void draw_object(PlayerTank tank); // function which draws playerTank based on its current parameters
    void load_TxSp(); // function loads all textures and sets them as sprites
    int choose_rotation(PlayerTank tank) const; // returns an angle at which playerTank should be drawn based on its current facing

public:
    SFMLPlayerTankView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLPLAYERTANKVIEW_H
