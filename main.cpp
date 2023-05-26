#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string.h>

#include <SFML/Graphics.hpp>

#include "game.h"

using namespace std;

int menu(sf::RenderWindow &window, sf::Vector2u windowSize, float size, sf::Font font)
{
    sf::Text text;
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setPosition(size / 2 - 110, (size + 100) / 2 - 110);
    bool flag = true;
    while(flag) 
    {
        window.setKeyRepeatEnabled(false);
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
                return -1;
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                return -1;
            }
            else if (event.type == sf::Event::Resized) 
            {
                window.setSize(windowSize);
            }
            else if (event.type == sf::Event::MouseButtonPressed && flag && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if ((localPosition.x >= size / 2 - 80 && localPosition.x <= size / 2 + 77.5) && (localPosition.y >= (size + 100) / 2 - 45 && localPosition.y <= (size + 100) / 2 + 35))
                {
                    flag = false;
                    return 0;
                }
            }

            window.clear(sf::Color(200, 200, 200));
            sf::RectangleShape rectangle(sf::Vector2f(117.5, 60));
            rectangle.setPosition(size / 2 - 130, (size + 100) / 2 - 105);
            window.draw(rectangle);
            string str = "START";
            text.setString(str);
            window.draw(text);
            window.display();
        }
    }

    return -1;

}

int main()
{
    srand(time(NULL));

    game game;
    game.add();

    sf::Sprite *sprites;

    sf::Font font;
    font.loadFromFile("fonts/EightBits.ttf");

    sf::RenderWindow window(sf::VideoMode(400, 500), "2048", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(760, 290));
    float size = sf::VideoMode::getDesktopMode().height / 2;
    sf::Vector2u windowSize(size, size + 100);
    window.setSize(windowSize);
    
    if (menu(window, windowSize, size, font) != 0) 
    {
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 0);

    sf::Text text1;
    text1.setPosition(0, 50);
    text1.setFont(font);
    text1.setCharacterSize(45);
    text1.setFillColor(sf::Color::Black);
    text1.setStyle(sf::Text::Bold);

    while(window.isOpen()) 
    {
        window.setKeyRepeatEnabled(false);
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized) 
            {
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
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
            {
                game.saveScore();
                game.restart();
            }
            window.clear(sf::Color(200, 200, 200));

            sprites = game.print();
            for (int i = 0; i < 16; i++)
            {
                window.draw(sprites[i]);
            }
            string str = "Score: " + to_string(game.getScore());
            string str1 = "Best score: " + to_string(game.getBestScore());
            text.setCharacterSize(45);
            text.setPosition(0, 0);
            text.setString(str);
            text1.setString(str1);
            window.draw(text);
            window.draw(text1);
            if (game.checkEnd())
            {
                window.clear(sf::Color(200, 200, 200));
                text.setCharacterSize(60);
                text.setPosition(size/2-160, (size-100)/2);
                string str = "GAME OVER!";
                text.setString(str);
                sf::Text text_rest;
                text_rest.setFont(font);
                text_rest.setCharacterSize(45);
                text_rest.setFillColor(sf::Color::Black);
                text_rest.setStyle(sf::Text::Bold);
                text_rest.setCharacterSize(40);
                text_rest.setPosition(size /2 - 170, (size-100) / 2 + 100);
                str = "Restart (press r)";
                text_rest.setString(str);
                window.draw(text);
                window.draw(text_rest);
            }
            window.display();
        }
    }

    game.saveScore();

    return 0;
}