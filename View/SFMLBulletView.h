//
// Created by IGOR on 23.06.2023.
//

#ifndef PLAGIATCITY_SFMLBULLETVIEW_H
#define PLAGIATCITY_SFMLBULLETVIEW_H

#include "../Bullets/Bullet.h"
#include "../GameBoard.h"
#include "TxSp.h"


class SFMLBulletView {
    GameBoard &board;

    std::vector<Bullet*> &bullets;

    TxSp bulletModel;

    sf::RenderWindow &win;

    void draw_object(Bullet* bullet);
    void load_TxSp();
    int choose_rotation(Bullet* bullet);

public:
    SFMLBulletView(GameBoard &b, sf::RenderWindow &w);

    void display();
};


#endif //PLAGIATCITY_SFMLBULLETVIEW_H
