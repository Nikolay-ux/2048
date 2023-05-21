#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include "game.h"

using namespace std;

int main()
{
    srand(time(NULL));
    game game;
    game.add();

    struct termios oldt, newt;
    int ch = 1;
    
    game.print();
    while (!game.checkEnd())
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
            game.left();
            break;
        case 119:
            game.up();
            break;
        case 100:
            game.right();
            break;
        case 115:
            game.down();
            break;
        case 48:
            return 0;
            break;
        default:
            break;
        }

        game.print();
    }

    game.saveScore();

    return 0;
}