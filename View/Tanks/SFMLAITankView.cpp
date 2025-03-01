//
// Created by IGOR on 21.06.2023.
//

#include "SFMLAITankView.h"

SFMLAITankView::SFMLAITankView(GameBoard &b, sf::RenderWindow &w) : board(b), AITanks(b.get_AITanks()), win(w)
{
    load_TxSp();
}

void SFMLAITankView::load_TxSp()
{

    if (!lightTankModel.tx.loadFromFile("../Textures/LightTank.png", sf::IntRect(1, 1, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    lightTankModel.sp.setTexture(lightTankModel.tx);
    if (!mediumTankModel.tx.loadFromFile("../Textures/MediumTank.png", sf::IntRect(1, 1, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    mediumTankModel.sp.setTexture(mediumTankModel.tx);
    if(!heavyTankModel.tx.loadFromFile("../Textures/HeavyTank.png", sf::IntRect(1, 1, TANK_WIDTH, TANK_HEIGHT)))
    {
        exit(1);
    }
    heavyTankModel.sp.setTexture(heavyTankModel.tx);

}

void SFMLAITankView::display()
{
    for(int indx=0; indx<static_cast<int>(AITanks.size()); indx++)
    {
        if(!AITanks[indx]->is_destroyed())
            draw_object(AITanks[indx]);
    }
}

void SFMLAITankView::draw_object(AITank* tank)
{
    TxSp *model = &choose_model(tank);
    model->sp.setOrigin(TANK_WIDTH/2.f, TANK_HEIGHT/2.f);
    model->sp.setRotation(choose_rotation(tank));
    model->sp.setPosition(tank->get_objectParam().object.left + TANK_WIDTH/2.f,tank->get_objectParam().object.top + TANK_HEIGHT/2.f);
    win.draw(model->sp);
}

int SFMLAITankView::choose_rotation(AITank *tank) const
{
    int rotation;
    switch (tank->get_objectParam().facing)
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

TxSp& SFMLAITankView::choose_model(AITank *tank)
{
    switch (tank->get_tankClass())
    {
        case LIGHT:
            return lightTankModel;
        case MEDIUM:
            return mediumTankModel;
        case HEAVY:
            return heavyTankModel;
        default:
            exit(1);
    }
}
