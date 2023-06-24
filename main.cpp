#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "View/SFMLView.h"
#include "Controllers/PlayerTankController.h"
#include "chrono"

int main() {

    sf::RenderWindow win(sf::VideoMode(800, 600), "PlagiatCity");
    GameBoard board;
    SFMLAITankView AITankView(board, win);
    SFMLPlayerTankView playerTankView(board, win);
    SFMLBulletView bulletView(board, win);
    SFMLWallView wallView(board, win);
    SFMLView view(board, AITankView, playerTankView, bulletView, wallView);
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

