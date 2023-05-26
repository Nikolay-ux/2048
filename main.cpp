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
                if ((localPosition.x >= size * 0.3518 && localPosition.x <= size * 0.6435) && (localPosition.y >= size * 0.5092 && localPosition.y <= size * 0.6574))
                {
                    flag = false;
                    return 0;
                }
                else if ((localPosition.x >= size * 0.3518 && localPosition.x <= size * 0.6435) && (localPosition.y >= size * 0.6943 && localPosition.y <= size * 0.8534))
                {
                    flag = false;
                    window.close();
                    return -1;
                }
            }
            window.clear(sf::Color(153, 102, 153));
            text.setPosition(size * 0.195, 0);
            text.setCharacterSize(150);
            text.setFillColor(sf::Color(51, 204, 102));
            string str = "2048";
            text.setString(str);
            window.draw(text);
            sf::RectangleShape rectangle(sf::Vector2f(size * 0.2175, size * 0.1111));
            rectangle.setFillColor(sf::Color(234, 125, 0));
            rectangle.setPosition(size * 0.2592, size * 0.3981);
            window.draw(rectangle);
            rectangle.setPosition(size * 0.2592, size * 0.5462);
            window.draw(rectangle);
            text.setCharacterSize(45);
            text.setFillColor(sf::Color(0, 0, 0));
            text.setPosition(size * 0.2962, size * 0.3888);
            str = "START";
            text.setString(str);
            window.draw(text);
            text.setPosition(size * 0.3055, size * 0.5370);
            str = "EXIT";
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

    sf::Texture table;
    table.loadFromFile("textures/table.png");
    sf::Sprite sprite;
    sprite.setTexture(table);
    sprite.setPosition(0.f, 100.f);
    sprite.setColor(sf::Color(0, 102, 102));

    sf::RenderWindow window(sf::VideoMode(400, 500), "2048", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(760, 290));
    float size = sf::VideoMode::getDesktopMode().height / 2;
    sf::Vector2u windowSize(size, size * 1.1851);
    window.setSize(windowSize);
    
    if (menu(window, windowSize, size, font) != 0) 
    {
        return 0;
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
                if (menu(window, windowSize, size, font) != 0)
                {
                    game.saveScore();
                    return 0;
                }
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
            window.clear(sf::Color(102, 153, 153));

            sprites = game.print();
            for (int i = 0; i < 16; i++)
            {
                window.draw(sprites[i]);
            }
            window.draw(sprite);
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
                window.clear(sf::Color(255, 204, 102));
                text.setCharacterSize(60);
                text.setPosition(size * 0.2037, size * 0.3248);
                string str = "GAME OVER!";
                text.setString(str);
                sf::Text text_rest;
                text_rest.setFont(font);
                text_rest.setCharacterSize(45);
                text_rest.setFillColor(sf::Color::Black);
                text_rest.setStyle(sf::Text::Bold);
                text_rest.setCharacterSize(40);
                text_rest.setPosition(size*0.1851, size * 0.5925);
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