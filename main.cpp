#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include <SFML/Graphics.hpp>

#include "game.h"

using namespace std;

int main()
{
    srand(time(NULL));
    game game;
    game.add();

    sf::RenderWindow window(sf::VideoMode(400, 500), "2048", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(760, 290));

    sf::Vector2u windowSize(400, 500);
    window.setSize(windowSize);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
                window.setSize(windowSize);
            window.clear(sf::Color(200, 200, 200));
            window.draw(shape);
            window.display();
        }
    }
    // struct termios oldt, newt;
    // int ch = 1;
    // while (ch)
    // {
    //     system("clear");
    //     game.print();
    //     tcgetattr(STDIN_FILENO, &oldt);
    //     newt = oldt;
    //     newt.c_lflag &= ~(ICANON | ECHO);
    //     tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    //     ch = getchar();
    //     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    //     switch (ch)
    //     {
    //     case 97:
    //         game.left();
    //         break;
    //     case 119:
    //         game.up();
    //         break;
    //     case 100:
    //         game.right();
    //         break;
    //     case 115:
    //         game.down();
    //         break;
    //     case 48:
    //         return 0;
    //         break;
    //     default:
    //         break;
    //     }
    // }
    return 0;
}