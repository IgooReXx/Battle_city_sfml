/*
 * Plagiat City made using SFML
 * Font used: Press Start 2P by CodeMan38 https://fonts.google.com/specimen/Press+Start+2P/about
 * Tank model inspired by: https://pixelartmaker.com/art/3cb4caf82e372fd
 */

#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "View/SFMLView.h"
#include "Controllers/PlayerTankController.h"
#include "Controllers/MenuController.h"

int main() {
    srand(time(0));

    sf::RenderWindow win(sf::VideoMode(800, 600), "PlagiatCity");
    win.setFramerateLimit(60);
    GameBoard board;
    SFMLView view(board, win);
    PlayerTankController ctrl(board.get_Player());
    MenuController menu(board, view.get_menuView());


    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        if(board.get_status() == MENU)
        {
            menu.menuControls(event);
        }
        if(board.get_status() == RUNNING)
        {
            ctrl.move();
            ctrl.shoot();
            board.update();
        }

        win.clear();
        view.draw();
        win.display();
    }
    return 0;

}

