//
// Created by IGOR on 17.06.2023.
//

#include "SFMLView.h"

SFMLView::SFMLView(GameBoard &b, sf::RenderWindow &win): board(b),
AITankView(b, win), playerTankView(b, win),
bulletView(b, win),
wallView(b, win), baseView(b, win), bonusHpView(b, win),
backgroundView(b, win),
menuView(win), gameOverView(win)
{

}

void SFMLView::draw()
{
    if(board.get_status() == MENU)
    {
        menuView.display();
    }
    else
    {
    backgroundView.display();
    AITankView.display();
    playerTankView.display();
    bulletView.display();
    wallView.display();
    baseView.display();
    bonusHpView.display();
    }
    if(board.get_status() == LOST)
        gameOverView.display_lost();
    if(board.get_status() == WON)
        gameOverView.display_won();
}

SFMLMenuView &SFMLView::get_menuView()
{
    return menuView;
}
