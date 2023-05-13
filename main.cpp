#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

const int edge = 4;
const int val = 8;

using namespace std;

void print(int A[][edge])
{
    for (int i = 0; i < edge; i++)
    {
        if (i == 0)
            cout << "___________________________" << endl;
        for (int j = 0; j < edge; j++)
        {
            if (A[i][j] != 0)
                printf("%5d |", A[i][j]);
            else
                printf("      |");
        }
        cout << endl;
        if (i + 1 != edge)
            cout << "------|------|------|------|" << endl;
        else
        {
            cout << "______|______|______|______|" << endl;
        }
    }
}

void zero(int A[][edge])
{
    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            A[i][j] = 0;
        }
    }
}

void add(int A[][edge])
{
    int values[val] = {2, 2, 2, 2, 2, 2, 2, 4};
    int *index = (int *)malloc(sizeof(int));
    int itr = 1;
    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            if (A[i][j] == 0)
            {
                index = (int *)realloc(index, itr * sizeof(int));
                index[itr - 1] = i * edge + j;
                itr++;
            }
        }
    }
    int randInd = index[rand() % (itr - 1)];
    A[randInd / edge][randInd % edge] = values[rand() % val];
}

void left(int A[][edge])
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (A[i][j] != 0 && A[i][j - 1] == 0)
                {
                    A[i][j - 1] = A[i][j];
                    A[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = 0; j < edge - 1; j++)
        {
            if (A[i][j] == A[i][j + 1] && A[i][j] != 0)
            {
                A[i][j] += A[i][j + 1];
                A[i][j + 1] = 0;
                j++;
                flag = true;
            }
        }
        k = 0;
        while(k <= 1) {
            for (int j = edge - 1; j > 0; j--)
            {
                if (A[i][j] != 0 && A[i][j - 1] == 0)
                {
                    A[i][j - 1] = A[i][j];
                    A[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add(A);
}

void up(int A[][edge])
{
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = edge - 1; j > 0; j--)
            {
                if (A[j][i] != 0 && A[j - 1][i] == 0)
                {
                    A[j - 1][i] = A[j][i];
                    A[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = 0; j < edge; j++)
        {
            if (A[j][i] == A[j + 1][i] && A[j][i] != 0)
            {
                A[j][i] += A[j + 1][i];
                A[j + 1][i] = 0;
                j++;
                flag = true;
            }
        }
        k = 0;
        while(k <= 1) {
            for (int j = edge - 1; j > 0; j--)
            {
                if (A[j][i] != 0 && A[j - 1][i] == 0)
                {
                    A[j - 1][i] = A[j][i];
                    A[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add(A);
}

void right(int A[][edge]) {
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (A[i][j] != 0 && A[i][j + 1] == 0)
                {
                    A[i][j + 1] = A[i][j];
                    A[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = edge - 1; j > 0; j--)
        {
            if (A[i][j] == A[i][j - 1] && A[i][j] != 0)
            {
                A[i][j] += A[i][j - 1];
                A[i][j - 1] = 0;
                j--;
                flag = true;
            }
        }
        k = 0;
        while(k <= 1) {
            for (int j = 0; j < edge - 1; j++)
            {
                if (A[i][j] != 0 && A[i][j + 1] == 0)
                {
                    A[i][j + 1] = A[i][j];
                    A[i][j] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add(A);
}

void down(int A[][edge]) {
    bool flag = false;
    for (int i = 0; i < edge; i++)
    {
        char k = 0;
        while (k <= 2)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (A[j][i] != 0 && A[j + 1][i] == 0)
                {
                    A[j + 1][i] = A[j][i];
                    A[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
        for (int j = edge - 1; j > 0; j--)
        {
            if (A[j][i] == A[j - 1][i] && A[j][i] != 0)
            {
                A[j][i] += A[j - 1][i];
                A[j - 1][i] = 0;
                j--;
                flag = true;
            }
        }
        k = 0;
        while (k <= 1)
        {
            for (int j = 0; j < edge - 1; j++)
            {
                if (A[j][i] != 0 && A[j + 1][i] == 0)
                {
                    A[j + 1][i] = A[j][i];
                    A[j][i] = 0;
                    flag = true;
                }
            }
            k++;
        }
    }
    if (flag)
        add(A);
}

int main()
{
    srand(time(NULL));
    int area[edge][edge];
    zero(area);
    struct termios oldt, newt;
    int ch = 1;
    int element = rand() % (edge * edge);
    const int val = 8;
    int values[val] = {2, 2, 2, 2, 2, 2, 2, 4};
    area[element / edge][element % edge] = values[rand() % val];
    system("clear");
    print(area);
    while (ch)
    {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        switch (ch)
        {
        case 97:
            left(area);
            system("clear");
            print(area);
            break;
        case 119:
            up(area);
            system("clear");
            print(area);
            break;
        case 100:
            right(area);
            system("clear");
            print(area);
            break;
        case 115:
            down(area);
            system("clear");
            print(area);
            break;
        case 48:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}