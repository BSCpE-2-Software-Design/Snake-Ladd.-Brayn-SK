#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int position;
public:
    Player(const std::string& playerName);
    void setPosition(int pos);
    void move(int steps);
    int getPosition() const;
    std::string getName() const;
};

#endif
