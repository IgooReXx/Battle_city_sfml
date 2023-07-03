//
// Created by IGOR on 03.07.2023.
//

#ifndef PLAGIATCITY_SFMLBONUSHPVIEW_H
#define PLAGIATCITY_SFMLBONUSHPVIEW_H

#include "../../GameBoard.h"
#include "../TxSp.h"

#include "../../Walls/PickUp.h"

class SFMLBonusHPView {

    GameBoard &board;
    PickUp* bonusHP;
    TxSp bonusHPModel;

    sf::RenderWindow &win;

    void draw_object(); // function which draws bonusHP based on its current parameters
    void load_TxSp(); // function loads all textures and sets them as sprites

    public:

    SFMLBonusHPView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLBONUSHPVIEW_H
