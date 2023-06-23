//
// Created by IGOR on 17.06.2023.
//

#ifndef PLAGIATCITY_SFMLVIEW_H
#define PLAGIATCITY_SFMLVIEW_H

#include "../GameBoard.h"
#include "SFMLAITankView.h"
#include "SFMLPlayerTankView.h"
#include "SFMLBulletView.h"
#include "SFMLWallView.h"

class SFMLView {
    GameBoard &board;

    SFMLAITankView &AITankView;
    SFMLPlayerTankView &playerTankView;
    SFMLBulletView &bulletView;
    SFMLWallView &wallView;
public:
    explicit SFMLView(GameBoard &b, SFMLAITankView &AIv, SFMLPlayerTankView &Pv, SFMLBulletView &Bv, SFMLWallView &Wv);
    void draw();
};


#endif //PLAGIATCITY_SFMLVIEW_H
