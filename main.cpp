#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "View/SFMLView.h"
#include "Controllers/PlayerTankController.h"
#include "chrono"

int main() {
    srand(time(0));

    sf::RenderWindow win(sf::VideoMode(800, 600), "PlagiatCity");
    GameBoard board;
    SFMLView view(board, win);
    PlayerTankController ctrl(board.get_Player());


    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
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

