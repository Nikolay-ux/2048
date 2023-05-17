#pragma one

class game
{
private:
    static const int edge = 4;
    int (*area)[edge] = new int[edge][edge];
    unsigned int score;

public:
    game();
    void print();
    void add();
    void left();
    void up();
    void right();
    void down();
};