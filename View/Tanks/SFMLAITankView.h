//
// Created by IGOR on 21.06.2023.
//

#ifndef PLAGIATCITY_SFMLAITANKVIEW_H
#define PLAGIATCITY_SFMLAITANKVIEW_H

#include "../../Tanks/AITank.h"
#include "../../GameBoard.h"
#include "../TxSp.h"

class SFMLAITankView {
    GameBoard &board;

    std::vector<AITank*> &AITanks;
    TxSp lightTankModel;
    TxSp mediumTankModel;
    TxSp heavyTankModel;

    sf::RenderWindow &win;

    void draw_object(AITank* tank); // function which draws AITanks based on their current parameters
    void load_TxSp(); // function loads all textures and sets them as sprites
    int choose_rotation(AITank* tank) const; // returns an angle at which AITanks should be drawn based on their current facing
    TxSp &choose_model(AITank* tank); // returns which sprite an AITanks should use based on its (tank) class

public:
    SFMLAITankView(GameBoard &b, sf::RenderWindow &w);

    void display(); // displays drawn object
};


#endif //PLAGIATCITY_SFMLAITANKVIEW_H
