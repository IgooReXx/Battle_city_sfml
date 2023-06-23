//
// Created by IGOR on 17.06.2023.
//

#include "SFMLView.h"

SFMLView::SFMLView(GameBoard &b, SFMLAITankView &AIv, SFMLPlayerTankView &Pv, SFMLBulletView &Bv, SFMLWallView &Wv)
: board(b), AITankView(AIv), playerTankView(Pv), bulletView(Bv), wallView(Wv)
{

}

void SFMLView::draw()
{
    AITankView.display();
    playerTankView.display();
    bulletView.display();
    wallView.display();
}
