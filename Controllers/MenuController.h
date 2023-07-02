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

    bool mouse_is_within_button(float mouseXPos, float mouseYPos, sf::FloatRect button); // function returns true if mouse is within the "play" button

public:
    MenuController(GameBoard &board, SFMLMenuView &view);

    void menuControls(sf::Event &event); // function allowing player to navigate the menu and handling menu logic
};


#endif //PLAGIATCITY_MENUCONTROLLER_H
