//
// Created by IGOR on 24.06.2023.
//

#ifndef PLAGIATCITY_SFMLWALLVIEW_H
#define PLAGIATCITY_SFMLWALLVIEW_H


#include "../../GameBoard.h"
#include "../TxSp.h"

class SFMLWallView {
    GameBoard &board;
    std::vector<Wall*> &walls;
    TxSp wallModel;
    sf::RenderWindow &win;

    void draw_object(Wall &wall); // function which draws walls based on their current parameters
    void load_TxSp(); // function loads all textures and sets them as sprites

public:
    SFMLWallView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLWALLVIEW_H
