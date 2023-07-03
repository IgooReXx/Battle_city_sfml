//
// Created by IGOR on 26.06.2023.
//

#ifndef PLAGIATCITY_SFMLBACKGROUNDVIEW_H
#define PLAGIATCITY_SFMLBACKGROUNDVIEW_H

#include "../TxSp.h"
#include "../../GameBoard.h"

class SFMLBackgroundView {

    GameBoard &board;
    sf::RenderWindow &win;

    TxSp background;
    sf::RectangleShape playablearea;
    sf::Font font;

    void draw_backgroud();
    void draw_player_HP();
    void load_TxSp();
    void load_font();


public:

    SFMLBackgroundView(GameBoard &b, sf::RenderWindow &w);
    void display();

};


#endif //PLAGIATCITY_SFMLBACKGROUNDVIEW_H
