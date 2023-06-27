//
// Created by IGOR on 27.06.2023.
//

#include "SFMLGameOverView.h"

SFMLGameOverView::SFMLGameOverView(sf::RenderWindow &w) : win(w)
{
    if(!gameOverScreen.tx.loadFromFile("../Textures/lost.png"))
    {
        exit(1);
    } gameOverScreen.sp.setTexture(gameOverScreen.tx);
    
    if(!gameWonScreen.tx.loadFromFile("../Textures/won.png"))
    {
        exit(1);
    } gameWonScreen.sp.setTexture(gameWonScreen.tx);

    int centreX = 400;
    int centreY = 285;
    gameOverScreen.sp.setOrigin(gameOverScreen.sp.getGlobalBounds().left + gameOverScreen.sp.getGlobalBounds().width / 2, gameOverScreen.sp.getGlobalBounds().top + gameOverScreen.sp.getGlobalBounds().height / 2);
    gameOverScreen.sp.setPosition(centreX, centreY);
    gameWonScreen.sp.setOrigin(gameWonScreen.sp.getGlobalBounds().left + gameWonScreen.sp.getGlobalBounds().width / 2, gameWonScreen.sp.getGlobalBounds().top + gameWonScreen.sp.getGlobalBounds().height / 2);
    gameWonScreen.sp.setPosition(centreX, centreY);
}

void SFMLGameOverView::display_lost()
{
    win.draw(gameOverScreen.sp);
}

void SFMLGameOverView::display_won()
{
    win.draw(gameWonScreen.sp);
}
