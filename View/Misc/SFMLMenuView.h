//
// Created by IGOR on 27.06.2023.
//

#ifndef PLAGIATCITY_SFMLMENUVIEW_H
#define PLAGIATCITY_SFMLMENUVIEW_H

#include "../TxSp.h"

#define BUTTON_LEFT 250
#define BUTTON_TOP 300

class SFMLMenuView {

    sf::RenderWindow &win;

    TxSp menuScreen;
    sf::RectangleShape playButton;
    sf::Font font;
    sf::Text buttonText;

public:

    SFMLMenuView(sf::RenderWindow &win);

    void display(); // displays drawn object

    //Simple getter:
    sf::FloatRect get_playButton();
};


#endif //PLAGIATCITY_SFMLMENUVIEW_H
