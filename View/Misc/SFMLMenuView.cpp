//
// Created by IGOR on 27.06.2023.
//

#include "SFMLMenuView.h"

SFMLMenuView::SFMLMenuView(sf::RenderWindow &win) : win(win)
{
    if(!font.loadFromFile("../Textures/PressStart2P-Regular.ttf"))
    {
        exit(1);
    }
    if(!menuScreen.tx.loadFromFile("../Textures/Menu.png"))
    {
        exit(1);
    } menuScreen.sp.setTexture(menuScreen.tx);

    playButton = sf::RectangleShape(sf::Vector2f(300, 100));
    playButton.setPosition(BUTTON_LEFT, BUTTON_TOP);
    playButton.setFillColor(sf::Color(16, 83, 16));
    playButton.setOutlineThickness(5);
    playButton.setOutlineColor(sf::Color::Black);

    buttonText.setFont(font);
    buttonText.setCharacterSize(64);
    buttonText.setString("PLAY");
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(playButton.getPosition().x+(playButton.getGlobalBounds().width-buttonText.getGlobalBounds().width)/2, BUTTON_TOP+18);




}

void SFMLMenuView::display()
{
    win.draw(menuScreen.sp);
    win.draw(playButton);
    win.draw(buttonText);

}

sf::FloatRect SFMLMenuView::get_playButton() {
    return playButton.getGlobalBounds();
}
