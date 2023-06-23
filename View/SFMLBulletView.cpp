//
// Created by IGOR on 23.06.2023.
//

#include "SFMLBulletView.h"

SFMLBulletView::SFMLBulletView(GameBoard &b, sf::RenderWindow &w) : board(b), bullets(b.get_bullets()), win(w)
{
    load_TxSp();
}

void SFMLBulletView::load_TxSp()
{

    if (!bulletModel.tx.loadFromFile("../textures/Bullet.png", sf::IntRect(0, 0, BULLET_WIDTH, BULLET_HEIGHT)))
    {
        exit(1);
    }
    bulletModel.sp.setTexture(bulletModel.tx);
}

void SFMLBulletView::display()
{
    for(int indx=0; indx<static_cast<int>(bullets.size()); indx++)
    {
        draw_object(bullets[indx]);
    }
}

void SFMLBulletView::draw_object(Bullet* bullet)
{
    bulletModel.sp.setOrigin(BULLET_WIDTH/2, BULLET_HEIGHT/2);
    bulletModel.sp.setRotation(choose_rotation(bullet));
    bulletModel.sp.setPosition(bullet->get_objectParam().object.left + BULLET_WIDTH/2,bullet->get_objectParam().object.top + BULLET_HEIGHT/2);
    win.draw(bulletModel.sp);
}

int SFMLBulletView::choose_rotation(Bullet *bullet)
{
    int rotation;
    switch (bullet->get_objectParam().facing)
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