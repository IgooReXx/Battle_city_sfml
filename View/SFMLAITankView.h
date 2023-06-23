//
// Created by IGOR on 21.06.2023.
//

#ifndef PLAGIATCITY_SFMLAITANKVIEW_H
#define PLAGIATCITY_SFMLAITANKVIEW_H

#include "../Tanks/AITank.h"
#include "../GameBoard.h"
#include "TxSp.h"

class SFMLAITankView {
    GameBoard &board;

    std::vector<AITank*> &AITanks;

    TxSp lightTankModel;
    TxSp mediumTankModel;
    TxSp heavyTankModel;

    sf::RenderWindow &win;

    void draw_object(AITank* tank);
    void load_TxSp();
    int choose_rotation(AITank* tank);
    TxSp &choose_model(AITank* tank);
public:
    SFMLAITankView(GameBoard &b, sf::RenderWindow &w);

    void display();
};


#endif //PLAGIATCITY_SFMLAITANKVIEW_H
