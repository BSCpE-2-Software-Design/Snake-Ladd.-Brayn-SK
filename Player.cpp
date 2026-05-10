#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName), position(0) {}

void Player::move(int steps) {
    position += steps;
}

void Player::setPosition(int pos) {
    position = pos;
}

int Player::getPosition() const {
    return position;
}

std::string Player::getName() const {
    return name;
}

