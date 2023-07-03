//
// Created by IGOR on 26.06.2023.
//

#include "SFMLBackgroundView.h"

SFMLBackgroundView::SFMLBackgroundView(GameBoard &b, sf::RenderWindow &w) : board(b), win(w)
{
    load_TxSp();
    load_font();
    playablearea = sf::RectangleShape(sf::Vector2f(PA_RIGHT-PA_LEFT, PA_BOTTOM-PA_TOP));
    playablearea.setPosition(PA_LEFT, PA_TOP);
    playablearea.setFillColor(sf::Color::Black);


}

void SFMLBackgroundView::load_TxSp()
{

    if (!background.tx.loadFromFile("../Textures/PlagiatCity.png", sf::IntRect(0, 0, MAP_WIDTH, MAP_HEIGHT)))
    {
        exit(1);
    }
    background.sp.setTexture(background.tx);
}

void SFMLBackgroundView::display()
{
    draw_backgroud();
}

void SFMLBackgroundView::draw_backgroud()
{
    win.draw(background.sp);
    win.draw(playablearea);
    draw_player_HP();
}

void SFMLBackgroundView::load_font()
{
    if(!font.loadFromFile("../Textures/PressStart2P-Regular.ttf"))
    {
        exit(1);
    }
}

void SFMLBackgroundView::draw_player_HP()
{
    bool doubleDigits = false;
    int HP = board.get_Player().get_HP();
    if(HP >= 10)
        doubleDigits = true;
    sf::Text playerHP;
    playerHP.setFont(font);
    playerHP.setString(std::to_string(HP));
    playerHP.setFillColor(sf::Color::Black);
    playerHP.setCharacterSize(32);
    if(doubleDigits)
        playerHP.setPosition(100, 103);
    else
        playerHP.setPosition(132, 103);
    win.draw(playerHP);
}
