//
// Created by IGOR on 23.06.2023.
//

#include "SFMLPlayerTankView.h"

SFMLPlayerTankView::SFMLPlayerTankView(GameBoard &b, sf::RenderWindow &w) : board(b), playerTank(b.get_Player()), win(w)
{
    load_TxSp();
}

void SFMLPlayerTankView::load_TxSp()
{

    if (!playerTankModel.tx.loadFromFile("../textures/PlayerTank.png", sf::IntRect(1, 1, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    playerTankModel.sp.setTexture(playerTankModel.tx);
}

void SFMLPlayerTankView::display()
{
    if(!playerTank.is_destroyed())
        draw_object(playerTank);
}

void SFMLPlayerTankView::draw_object(PlayerTank tank)
{
    playerTankModel.sp.setOrigin(TANK_WIDTH/2.f, TANK_HEIGHT/2.f);
    playerTankModel.sp.setRotation(choose_rotation(tank));
    playerTankModel.sp.setPosition(tank.get_objectParam().object.left + TANK_WIDTH/2,tank.get_objectParam().object.top + TANK_HEIGHT/2);
    win.draw(playerTankModel.sp);
}

int SFMLPlayerTankView::choose_rotation(PlayerTank tank) const
{
    int rotation;
    switch (tank.get_objectParam().facing)
    {
        case UP:
            rotation = 0;
            break;
        case DOWN:
            rotation = 180;
            break;
        case LEFT:
            rotation = -90;
            break;
        case RIGHT:
            rotation = 90;
            break;
    }
    return rotation;
}
