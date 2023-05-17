#include <iostream>

#include "game.h"

using namespace std;

game::game()
{
    score = 0;
}
void game::print()
{
    cout << "Score: " << score << endl;
    cout << "____________________________" << endl;
    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (area[i][j] != 0)
                printf("|%5d ", area[i][j]);
            else
                printf("|      ");
        }
        cout << "|" << endl;
        if (i + 1 != edge)
            cout << "|------|------|------|------|" << endl;
        else
        {
            cout << "|______|______|______|______|" << endl;
        }
    }
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