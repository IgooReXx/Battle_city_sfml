//
// Created by IGOR on 17.06.2023.
//

#include "SFMLView.h"

SFMLView::SFMLView(GameBoard &b, sf::RenderWindow &win):
AITankView(b, win), playerTankView(b, win), bulletView(b, win), wallView(b, win), baseView(b, win), backgroundView(b, win)
{

}

void SFMLView::draw()
{
    backgroundView.display();
    AITankView.display();
    playerTankView.display();
    bulletView.display();
    wallView.display();
    baseView.display();
}
