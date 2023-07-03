//
// Created by IGOR on 17.06.2023.
//

// inspiracja modelem https://pixelartmaker.com/art/3cb4caf82e372fd

#ifndef PLAGIATCITY_SFMLVIEW_H
#define PLAGIATCITY_SFMLVIEW_H

#include "../GameBoard.h"

#include "Tanks/SFMLAITankView.h"
#include "Tanks/SFMLPlayerTankView.h"

#include "Bullets/SFMLBulletView.h"

#include "Walls/SFMLWallView.h"
#include "Walls/SFMLBaseView.h"
#include "Walls/SFMLBonusHPView.h"

#include "Misc/SFMLBackgroundView.h"
#include "Misc/SFMLMenuView.h"
#include "Misc/SFMLGameOverView.h"

/// Class handles display of every object on the map each object has its own subclass which is responsible for drawing that object
class SFMLView {

    GameBoard &board;

    SFMLAITankView AITankView;
    SFMLPlayerTankView playerTankView;

    SFMLBulletView bulletView;

    SFMLWallView wallView;
    SFMLBaseView baseView;
    SFMLBonusHPView bonusHpView;

    SFMLBackgroundView backgroundView;
    SFMLMenuView menuView;
    SFMLGameOverView gameOverView;

public:
    explicit SFMLView(GameBoard &b, sf::RenderWindow &win);

    // function calls all display functions in View subclasses
    void draw();

    // Simple getter
    SFMLMenuView &get_menuView();
};


#endif //PLAGIATCITY_SFMLVIEW_H
