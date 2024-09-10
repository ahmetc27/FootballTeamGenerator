#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

enum Position {
    DEFENSIVE,
    OFFENSIVE,
    MIDFIELD,
    GOALKEEPER
};

class Player
{
    public:
        Player(std::string name, int rating, Position position);
        virtual ~Player();
        std::string getName();
        int getRating();
        Position getPosition();
        bool hasPinny();
        void setPinny(bool setPinny);

    private:
        std::string name;
        int rating;
        Position position;
        bool pinny;
};

#endif // PLAYER_H
