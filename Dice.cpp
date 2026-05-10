#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    srand(static_cast<unsigned>(time(NULL)));
}

int Dice::roll() {
    return 1 + rand() % 6;
}
