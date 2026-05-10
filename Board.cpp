#include "Board.h"
#include <iostream>
#include <cstdlib>

void Board::display() const {
    system("cls");
    std::cout << "\n\n";
    for (int i = 0; i < 52; ++i) std::cout << "-";
    std::cout << "\n| Snake at Position \t|\tLadder at Position |\n";
    for (int i = 0; i < 52; ++i) std::cout << "-";
    std::cout << "\n| From 98 to 28 \t|\tFrom 8  to 26      |\n";
    std::cout << "| From 92 to 51 \t|\tFrom 21 to 82      |\n";
    std::cout << "| From 83 to 19 \t|\tFrom 43 to 77      |\n";
    std::cout << "| From 69 to 33 \t|\tFrom 50 to 91      |\n";
    std::cout << "| From 59 to 17 \t|\tFrom 62 to 96      |\n";
    std::cout << "| From 48 to 9  \t|\tFrom 66 to 87      |\n";
    std::cout << "| From 46 to 5  \t|\tFrom 80 to 100     |\n";
    for (int i = 0; i < 52; ++i) std::cout << "-";
    std::cout << std::endl;
}

int Board::checkPosition(int pos) const {
    switch (pos) {
    case 98: return 28;
    case 92: return 51;
    case 83: return 19;
    case 69: return 33;
    case 59: return 17;
    case 48: return 9;
    case 46: return 5;
    case 8:  return 26;
    case 21: return 82;
    case 43: return 77;
    case 50: return 91;
    case 54: return 93;
    case 62: return 96;
    case 66: return 87;
    case 80: return 100;
    default: return pos;
    }
}
