#include <iostream>
#include <ctime>
#include <cstdlib>

int game(int maxnum) {
    int count = 0;
    int rnum = rand() % maxnum + 1;
    int num;

    while (true) {
        std::cout << "Anna luku: ";

        // fixi johonki ihan random ongelmaan
        if (!(std::cin >> num)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        count++;

        if (rnum > num) {
            std::cout << "Lukusi on suurempi\n";
        } else if (rnum < num) {
            std::cout << "Lukusi on pienempi\n";
        } else {
            std::cout << "Lukusi on yhtäsuuri\n";
            break;
        }
    }

    return count;

}

int main() {
    srand(time(0));

    int maxnum = 20;

    int guesses = game(maxnum);
    // En saanut kirveelläkään toimimaan QT:eessä. Toimii kuitenkin toisilla kääntäjillä
    std::cout << "Arvasit oikein " << guesses << " yrityksellä" << std::endl;

    return 0;
}

