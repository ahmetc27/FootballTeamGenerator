#include "Player.h"

Player::Player(std::string name, int rating, Position position) : name(name), rating(rating), position(position)
{
    pinny = false;
}

Player::~Player() {}

std::string Player::getName() { return name; }

int Player::getRating() { return rating; }

Position Player::getPosition() { return position; }

bool Player::hasPinny() { return pinny; }

void Player::setPinny(bool setPinny) { pinny = setPinny; }
