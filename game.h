#pragma one

class game
{
private:
    static const int edge = 4;
    int (*area)[edge] = new int[edge][edge];
    sf::Texture *textures = new sf::Texture[14];

public:
    unsigned int score;
    unsigned int best_score;
    game();
    sf::Sprite *print();
    void add();
    void left();
    void up();
    void right();
    void down();
    bool checkEnd();
    unsigned int openScore();
    void saveScore();
    void restart();
};