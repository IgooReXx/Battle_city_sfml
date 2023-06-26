//
// Created by IGOR on 17.06.2023.
//

// inspiracja modelem https://pixelartmaker.com/art/3cb4caf82e372fd

#ifndef PLAGIATCITY_SFMLVIEW_H
#define PLAGIATCITY_SFMLVIEW_H

#include "../GameBoard.h"
#include "SFMLAITankView.h"
#include "SFMLPlayerTankView.h"
#include "SFMLBulletView.h"
#include "SFMLWallView.h"
#include "SFMLBaseView.h"
#include "SFMLBackgroundView.h"

class SFMLView {

    SFMLAITankView AITankView;
    SFMLPlayerTankView playerTankView;
    SFMLBulletView bulletView;
    SFMLWallView wallView;
    SFMLBaseView baseView;
    SFMLBackgroundView backgroundView;
public:
    explicit SFMLView(GameBoard &b, sf::RenderWindow &win);
    void draw();
};


#endif //PLAGIATCITY_SFMLVIEW_H
