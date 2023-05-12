#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

#define EDGE 4
#define VAL 5

using namespace std;

void print(int A[][EDGE]) {
    for(int i = 0; i < EDGE; i++) {
        if(i == 0)
            cout << "___________________________" << endl;
        for(int j = 0; j < EDGE; j++) {
            if(A[i][j] != 0)
                printf("%5d |", A[i][j]);
            else
                printf("      |");
        }
        cout << endl;
        if(i + 1 != EDGE)
            cout << "------|------|------|------|" << endl;
        else {
            cout << "______|______|______|______|" << endl;
        }
    }
}

void zero(int A[][EDGE]) {
    for(int i = 0; i < EDGE; i++) {
        for(int j = 0; j < EDGE; j++) {
            A[i][j] = 0;
        }
    }
}

int main()
{

    srand(time(NULL));
    int area[EDGE][EDGE];
    zero(area);
    struct termios oldt, newt;
    int ch = 1;
    int element = rand() % (EDGE * EDGE);
    int values[VAL] = {2, 2, 2, 2, 4};
    area[element / EDGE][element % EDGE] = values[rand() % VAL];
    system("clear");
    print(area);
    return 0;
}