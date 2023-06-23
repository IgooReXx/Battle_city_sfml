//
// Created by IGOR on 24.06.2023.
//

#include "SFMLWallView.h"

SFMLWallView::SFMLWallView(GameBoard &b, sf::RenderWindow &w) : board(b), walls(b.get_Walls()), win(w)
{
    load_TxSp();
}

void SFMLWallView::load_TxSp()
{

    if (!wallModel.tx.loadFromFile("../textures/Wall.png", sf::IntRect(0, 0, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    wallModel.sp.setTexture(wallModel.tx);
}

void SFMLWallView::display()
{
    for(int indx=0; indx < static_cast<int>(board.get_Walls().size()); indx++)
    {
        draw_object(walls[indx]);
    }
}

void SFMLWallView::draw_object(Wall &wall)
{
    wallModel.sp.setOrigin(TANK_WIDTH/2, TANK_HEIGHT/2);
    wallModel.sp.setPosition(wall.get_objectParam().object.left + TANK_WIDTH/2,wall.get_objectParam().object.top + TANK_HEIGHT/2);
    win.draw(wallModel.sp);
}