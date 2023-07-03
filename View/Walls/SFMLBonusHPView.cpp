//
// Created by IGOR on 03.07.2023.
//

#include "SFMLBonusHPView.h"
#include "iostream"

SFMLBonusHPView::SFMLBonusHPView(GameBoard &b, sf::RenderWindow &w) : board(b), bonusHP(b.get_bonusHP()), win(w)
{
    load_TxSp();
}

void SFMLBonusHPView::load_TxSp()
{

    if (!bonusHPModel.tx.loadFromFile("../Textures/HP.png", sf::IntRect(0, 0, WALL_WIDTH*2, WALL_HEIGHT*2)))
    {
        exit(1);
    }
    bonusHPModel.sp.setTexture(bonusHPModel.tx);
}

void SFMLBonusHPView::display()
{
    if(bonusHP == nullptr)
        bonusHP = board.get_bonusHP();

    if(!board.get_bonusPickedUp() and bonusHP != nullptr)
        draw_object();

}

void SFMLBonusHPView::draw_object()
{
    bonusHPModel.sp.setOrigin(WALL_WIDTH*2/2, WALL_HEIGHT*2/2);
    bonusHPModel.sp.setPosition(bonusHP->get_objectParam().object.left + WALL_WIDTH*2/2,bonusHP->get_objectParam().object.top + WALL_HEIGHT*2/2);
    win.draw(bonusHPModel.sp);
}