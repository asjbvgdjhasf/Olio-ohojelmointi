#ifndef GAME_H
#define GAME_H

class game {
private:
    int maxnum;
    int rnum;
    int count;

public:
    game(int maxnum);
    void play();
    void printGameResult();
};

#endif