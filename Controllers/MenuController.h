//
// Created by IGOR on 27.06.2023.
//

#ifndef PLAGIATCITY_MENUCONTROLLER_H
#define PLAGIATCITY_MENUCONTROLLER_H

#include "../GameBoard.h"
#include "../View/SFMLMenuView.h"

class MenuController {
    GameBoard &board;
    SFMLMenuView &view;

    bool mouse_is_within_button(float mouseXPos, float mouseYPos, sf::FloatRect button);

public:
    MenuController(GameBoard &board, SFMLMenuView &view);

    void menuControls(sf::Event &event);
};


#endif //PLAGIATCITY_MENUCONTROLLER_H
