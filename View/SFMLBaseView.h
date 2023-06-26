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
       void draw_object(Wall &wall);
       void load_TxSp();
public:

    SFMLBaseView(GameBoard &b, sf::RenderWindow &w);
    void display();
};


#endif //PLAGIATCITY_SFMLBASEVIEW_H
