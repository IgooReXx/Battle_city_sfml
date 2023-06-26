//
// Created by IGOR on 23.06.2023.
//

#ifndef PLAGIATCITY_SFMLPLAYERTANKVIEW_H
#define PLAGIATCITY_SFMLPLAYERTANKVIEW_H

#include "../Tanks/PlayerTank.h"
#include "../GameBoard.h"
#include "TxSp.h"

class SFMLPlayerTankView {
    GameBoard &board;

    PlayerTank &playerTank;

    TxSp playerTankModel;

    sf::RenderWindow &win;

    void draw_object(PlayerTank tank);
    void load_TxSp();
    int choose_rotation(PlayerTank tank) const;

public:
    SFMLPlayerTankView(GameBoard &b, sf::RenderWindow &w);

    void display();
};


#endif //PLAGIATCITY_SFMLPLAYERTANKVIEW_H
