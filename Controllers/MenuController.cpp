//
// Created by IGOR on 27.06.2023.
//

#include "MenuController.h"

MenuController::MenuController(GameBoard &b, SFMLMenuView &v) : board(b), view(v)
{

}

void MenuController::menuControls(sf::Event &event)
{
    if(event.mouseButton.button != sf::Mouse::Left)
        return;

    float mouseXPos = event.mouseButton.x;
    float mouseYPos = event.mouseButton.y;
    sf::FloatRect playButton = view.get_playButton();

    if(mouse_is_within_button(mouseXPos, mouseYPos, playButton))
    {
        board.set_status_RUNNING();
    }
}

bool MenuController::mouse_is_within_button(float mouseXPos, float mouseYPos, sf::FloatRect button)
{
    if(!(mouseXPos >= button.left))
        return false;
    if(!(mouseXPos <= button.left + button.width))
        return false;
    if(!(mouseYPos >= button.top))
        return false;
    if(!(mouseYPos <= button.top + button.height))
        return false;
    return true;
}