#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "game.h"

using namespace std;

game::game()
{
    score = 0;
    best_score = openScore();
}
sf::Sprite *game::print()
{
    sf::Texture *textures = new sf::Texture[14];
    textures[0].loadFromFile("textures/2.png");
    textures[1].loadFromFile("textures/4.png");
    textures[2].loadFromFile("textures/8.png");
    textures[3].loadFromFile("textures/16.png");
    textures[4].loadFromFile("textures/32.png");
    textures[5].loadFromFile("textures/64.png");
    textures[6].loadFromFile("textures/128.png");
    textures[7].loadFromFile("textures/256.png");
    textures[8].loadFromFile("textures/512.png");
    textures[9].loadFromFile("textures/1024.png");
    textures[10].loadFromFile("textures/2048.png");
    textures[11].loadFromFile("textures/4096.png");
    textures[12].loadFromFile("textures/8192.png");
    textures[13].loadFromFile("textures/16384.png");

    sf::Sprite *sprites = new sf::Sprite[16];
    
    for (int i = 0; i < edge; i++)
    {
        for (int j = edge - 1; j >= 0; j--)
        {
            if (area[i][j] == 2)
            {
                sprites[i * 4 + j].setTexture(textures[0]);
                
            }
            else if (area[i][j] == 4)
            {
                sprites[i * 4 + j].setTexture(textures[1]);
            }
            else if (area[i][j] == 8)
            {
                sprites[i * 4 + j].setTexture(textures[2]);
            }
            else if (area[i][j] == 16)
            {
                sprites[i * 4 + j].setTexture(textures[3]);
            }
            else if (area[i][j] == 32)
            {
                sprites[i * 4 + j].setTexture(textures[4]);
            }
            else if (area[i][j] == 64)
            {
                sprites[i * 4 + j].setTexture(textures[5]);
            }
            else if (area[i][j] == 128)
            {
                sprites[i * 4 + j].setTexture(textures[6]);
            }
            else if (area[i][j] == 256)
            {
                sprites[i * 4 + j].setTexture(textures[7]);
            }
            else if (area[i][j] == 512)
            {
                sprites[i * 4 + j].setTexture(textures[8]);
            }
            else if (area[i][j] == 1024)
            {
                sprites[i * 4 + j].setTexture(textures[9]);
            }
            else if (area[i][j] == 2048)
            {
                sprites[i * 4 + j].setTexture(textures[10]);
            }
            else if (area[i][j] == 4096)
            {
                sprites[i * 4 + j].setTexture(textures[11]);
            }
            else if (area[i][j] == 8192)
            {
                sprites[i * 4 + j].setTexture(textures[12]);
            }
            else if (area[i][j] == 16384)
            {
                sprites[i * 4 + j].setTexture(textures[13]);
            }
            sprites[i * 4 + j].setPosition(sf::Vector2f((j) * (100.f), (i + 1) * (100.f)));
        }
    }
    return sprites;
}

void game::add()
{
    const int val = 8;
    int values[val] = {2, 2, 2, 2, 2, 2, 2, 4};
    int *index = (int *)malloc(sizeof(int));
    int itr = 1;
    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (area[i][j] == 0)
            {
                index = (int *)realloc(index, itr * sizeof(int));
                index[itr - 1] = i * edge + j;
                itr++;
            }
        }
    }
    int randInd = index[rand() % (itr - 1)];
    area[randInd / edge][randInd % edge] = values[rand() % val];
    free(index);
}

void game::left()
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (area[i][j] != 0 && area[i][j - 1] == 0)
                {
                    area[i][j - 1] = area[i][j];
                    area[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = 0; j < edge - 1; j++)
        {
            if (area[i][j] == area[i][j + 1] && area[i][j] != 0)
            {
                area[i][j] += area[i][j + 1];
                area[i][j + 1] = 0;

                score += area[i][j];

                j++;
                flag = true;
            }
        }
        k = 0;
        while (k <= 1)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (area[i][j] != 0 && area[i][j - 1] == 0)
                {
                    area[i][j - 1] = area[i][j];
                    area[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add();
}

void game::up()
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (area[j][i] != 0 && area[j - 1][i] == 0)
                {
                    area[j - 1][i] = area[j][i];
                    area[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = 0; j < edge; j++)
        {
            if (area[j][i] == area[j + 1][i] && area[j][i] != 0)
            {
                area[j][i] += area[j + 1][i];
                area[j + 1][i] = 0;

                score += area[j][i];

                j++;
                flag = true;
            }
        }
        k = 0;
        while (k <= 1)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (area[j][i] != 0 && area[j - 1][i] == 0)
                {
                    area[j - 1][i] = area[j][i];
                    area[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add();
}

void game::right()
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (area[i][j] != 0 && area[i][j + 1] == 0)
                {
                    area[i][j + 1] = area[i][j];
                    area[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = edge - 1; j > 0; j--)
        {
            if (area[i][j] == area[i][j - 1] && area[i][j] != 0)
            {
                area[i][j] += area[i][j - 1];
                area[i][j - 1] = 0;

                score += area[i][j];

                j--;
                flag = true;
            }
        }
        k = 0;
        while (k <= 1)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (area[i][j] != 0 && area[i][j + 1] == 0)
                {
                    area[i][j + 1] = area[i][j];
                    area[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add();
}

void game::down()
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (area[j][i] != 0 && area[j + 1][i] == 0)
                {
                    area[j + 1][i] = area[j][i];
                    area[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = edge - 1; j > 0; j--)
        {
            if (area[j][i] == area[j - 1][i] && area[j][i] != 0)
            {
                area[j][i] += area[j - 1][i];
                area[j - 1][i] = 0;

                score += area[j][i];

                j--;
                flag = true;
            }
        }
        k = 0;
        while (k <= 1)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (area[j][i] != 0 && area[j + 1][i] == 0)
                {
                    area[j + 1][i] = area[j][i];
                    area[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add();
}

bool game::checkEnd()
{
    for (int i = 0; i < edge; i++) 
    {

        for (int j = 0; j < edge; j++)
        {
            if (area[i][j] == 0) 
            {
                return false;
            }
        }

        for (int j = 0; j < edge - 1; j++)
        {
            if (area[i][j] == area[i][j + 1])
            {
                return false;
            }
            if (area[j][i] == area[j + 1][i]) {
                return false;
            }
        }
    }

    return true;
}

unsigned int game::openScore()
{
    ifstream file("save_score.dat", fstream::binary);
    
    if (!file.is_open()) 
    {
        return 0;
    } 
    else 
    {
        string buf;

        file >> buf;
        file.close();

        return std::stoi(buf);
    }
}

void game::saveScore()
{
    if (score > best_score)
    {
    ofstream file("save_score.dat", fstream::binary);

    file << score << endl;

    file.close();
    }
}