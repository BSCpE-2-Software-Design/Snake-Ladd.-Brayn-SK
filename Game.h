#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dice.h"
#include "Board.h"
#include <string>

class Game {
private:
    Player player1;
    Player player2;
    Dice dice;
    Board board;

    void draw_line(int n, char ch) const;
    void showScore() const;

public:
    Game(const std::string& name1, const std::string& name2);
    void start();
};

#endif
