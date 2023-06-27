//
// Created by IGOR on 27.06.2023.
//

#ifndef PLAGIATCITY_SFMLGAMEOVERVIEW_H
#define PLAGIATCITY_SFMLGAMEOVERVIEW_H

#include "TxSp.h"

class SFMLGameOverView {
    sf::RenderWindow &win;
    TxSp gameOverScreen;
    TxSp gameWonScreen;

public:
    SFMLGameOverView(sf::RenderWindow &w);
    void display_lost();
    void display_won();

};


#endif //PLAGIATCITY_SFMLGAMEOVERVIEW_H
