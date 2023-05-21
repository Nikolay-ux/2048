#pragma one

class game
{
private:
    static const int edge = 4;
    int (*area)[edge] = new int[edge][edge];
    unsigned int score;
    unsigned int best_score;

public:
    game();
    void print();
    void add();
    void left();
    void up();
    void right();
    void down();
    bool checkEnd();
    unsigned int openScore();
    void saveScore();
};