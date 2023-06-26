//
// Created by IGOR on 25.06.2023.
//

#include "SFMLBaseView.h"

SFMLBaseView::SFMLBaseView(GameBoard &b, sf::RenderWindow &w) : board(b), base(b.get_base()), win(w)
{
    load_TxSp();
}

void SFMLBaseView::load_TxSp()
{

    if (!baseModel.tx.loadFromFile("../textures/Base.png", sf::IntRect(0, 0, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    baseModel.sp.setTexture(baseModel.tx);
}

void SFMLBaseView::display()
{
    if(!base->is_destroyed())
        draw_object(*base);
}

void SFMLBaseView::draw_object(Wall &wall)
{
    baseModel.sp.setOrigin(TANK_WIDTH/2, TANK_HEIGHT/2);
    baseModel.sp.setPosition(wall.get_objectParam().object.left + TANK_WIDTH/2,wall.get_objectParam().object.top + TANK_HEIGHT/2);
    win.draw(baseModel.sp);
}