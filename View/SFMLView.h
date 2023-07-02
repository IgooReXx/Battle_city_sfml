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
#include "SFMLMenuView.h"
#include "SFMLGameOverView.h"

/// Class handles display of every object on the map each object has its own subclass which is responsible for drawing that object
class SFMLView {

    GameBoard &board;

    SFMLAITankView AITankView;
    SFMLPlayerTankView playerTankView;
    SFMLBulletView bulletView;
    SFMLWallView wallView;
    SFMLBaseView baseView;
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
