#include "Game.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

Game::Game(const std::string& name1, const std::string& name2)
    : player1(name1), player2(name2) {
}

void Game::draw_line(int n, char ch) const {
    for (int i = 0; i < n; ++i)
        std::cout << ch;
}

void Game::showScore() const {
    std::cout << "\n";
    draw_line(52, '-');
    std::cout << "\n\t\tGAME STATUS\n";
    draw_line(52, '-');
    std::cout << "\n > " << player1.getName() << " is at position " << player1.getPosition() << std::endl;
    std::cout << " > " << player2.getName() << " is at position " << player2.getPosition() << std::endl;
    draw_line(52, '_');
    std::cout << std::endl;
}

void Game::start() {
    system("cls");

    draw_line(50, '='); std::cout << "\n";
    draw_line(50, '='); std::cout << "\n";
    draw_line(50, '=');
    std::cout << "\n\t\tSNAKE & LADDER GAME\n";
    draw_line(50, '='); std::cout << "\n";
    draw_line(50, '='); std::cout << "\n";
    draw_line(50, '=');

    while (player1.getPosition() < 100 && player2.getPosition() < 100) {
        board.display();
        showScore();

        // Player 1 turn
        std::cout << "\n\n >>> " << player1.getName() << " - Now your turn. Press any key to play ";
        _getch();
        int lastpos = player1.getPosition();
        int roll = dice.roll();
        std::cout << "\nYou got " << roll << " point(s)!";
        player1.move(roll);
        std::cout << " Now you are at position " << player1.getPosition() << "\n";
        player1.setPosition(board.checkPosition(player1.getPosition()));

        if (player1.getPosition() > 100) {
            player1.setPosition(lastpos);
            std::cout << "\nYou need an exact roll to reach 100. Back to position " << player1.getPosition() << "\n";
        }
        else {
            if (player1.getPosition() < lastpos)
                std::cout << "\n\aOops!! Snake found!! You are at position " << player1.getPosition() << "\n";
            else if (player1.getPosition() > lastpos + 6)
                std::cout << "\nGreat!! You got a ladder!! You are at position " << player1.getPosition() << "\n";
        }

        if (player1.getPosition() >= 100) break;

        // Player 2 turn
        std::cout << "\n\n >>> " << player2.getName() << " - Now your turn. Press any key to play ";
        _getch();
        lastpos = player2.getPosition();
        roll = dice.roll();
        std::cout << "\nYou got " << roll << " point(s)!";
        player2.move(roll);
        std::cout << " Now you are at position " << player2.getPosition() << "\n";
        player2.setPosition(board.checkPosition(player2.getPosition()));

        if (player2.getPosition() > 100) {
            player2.setPosition(lastpos);
            std::cout << "\nYou need an exact roll to reach 100. Back to position " << player2.getPosition() << "\n";
        }
        else {
            if (player2.getPosition() < lastpos)
                std::cout << "\n\n\aOops!! Snake found!! You are at position " << player2.getPosition() << "\n";
            else if (player2.getPosition() > lastpos + 6)
                std::cout << "\n\nGreat!! You got a ladder!! You are at position " << player2.getPosition() << "\n";
        }

        _getch();
    }

    system("cls");
    std::cout << "\n\n\n";
    draw_line(52, '#');
    std::cout << "\n\t\tRESULT\n\n";
    draw_line(52, '#');
    std::cout << std::endl;
    showScore();
    std::cout << "\n\n\n";
    if (player1.getPosition() >= 100)
        std::cout << "Congratulations!!! " << player1.getName() << ", you won the game\n\n";
    else
        std::cout << "Congratulations!!! " << player2.getName() << ", you won the game\n\n";
    draw_line(52, '#');
    _getch();
}
