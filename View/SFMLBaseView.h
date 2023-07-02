//
// Created by IGOR on 25.06.2023.
//

#ifndef PLAGIATCITY_SFMLBASEVIEW_H
#define PLAGIATCITY_SFMLBASEVIEW_H

#include "../GameBoard.h"
#include "TxSp.h"

class SFMLBaseView {

       GameBoard &board;

       Wall* base;
       TxSp baseModel;

       sf::RenderWindow &win;

       void draw_object(Wall &wall); // function which draws base based on its current parameters
       void load_TxSp(); // function loads all textures and sets them as sprites

public:

    SFMLBaseView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLBASEVIEW_H
