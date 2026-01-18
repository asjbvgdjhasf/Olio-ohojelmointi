#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game.h"

int main() {
    srand(time(0));

    int maxnum = 20;

    game peli(maxnum);
    peli.play();

    return 0;
}