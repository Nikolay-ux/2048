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

    sf::Sprite *sprites;

    sf::Font font;
    font.loadFromFile("fonts/EightBits.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(400, 500), "2048", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(760, 290));
    sf::Vector2u windowSize(400, 500);
    window.setSize(windowSize);
    
    while (window.isOpen())
    {
        window.setKeyRepeatEnabled(false);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
            else if (event.type == sf::Event::Resized) {
                window.setSize(windowSize);
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D))
            {
                game.right();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
            {
                game.left();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S))
            {
                game.down();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
            {
                game.up();
            }
            window.clear(sf::Color(200, 200, 200));
            sprites = game.print();
            for (int i = 0; i < 16; i++)
            {
                window.draw(sprites[i]);
            }
            string variableString = "Score: " + to_string(game.score);
            text.setString(variableString);
            window.draw(text);
            window.display();
        }
    }
    return 0;
}