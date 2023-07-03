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

    if (!baseModel.tx.loadFromFile("../Textures/Base.png", sf::IntRect(0, 0, WALL_WIDTH*2, WALL_HEIGHT*2)))
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
    baseModel.sp.setOrigin(WALL_WIDTH*2/2, WALL_HEIGHT*2/2);
    baseModel.sp.setPosition(wall.get_objectParam().object.left + WALL_WIDTH*2/2,wall.get_objectParam().object.top + WALL_HEIGHT*2/2);
    win.draw(baseModel.sp);
}