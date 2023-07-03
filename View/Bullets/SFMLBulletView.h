//
// Created by IGOR on 23.06.2023.
//

#ifndef PLAGIATCITY_SFMLBULLETVIEW_H
#define PLAGIATCITY_SFMLBULLETVIEW_H

#include "../../Bullets/Bullet.h"
#include "../../GameBoard.h"
#include "../TxSp.h"


class SFMLBulletView {
    GameBoard &board;

    std::vector<Bullet*> &bullets;
    TxSp bulletModel;

    sf::RenderWindow &win;

    void draw_object(Bullet* bullet); // function which draws bullets based on their current parameters
    void load_TxSp(); // function loads all textures and sets them as sprites
    int choose_rotation(Bullet* bullet); // returns an angle at which bullets should be drawn based on their current facing

public:
    SFMLBulletView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLBULLETVIEW_H
