#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Team
{
    public:
        Team();
        virtual ~Team();
        void addPlayer(Player&& player);
        void shufflePlayers();
        void sortPlayers();
        void createTeams();
        void printTeamWithRating(std::vector<Player>& team);
        void printTeam(std::vector<Player>& team);
        void checkScore(std::vector<Player>& team);
        std::vector<Player>& getTeam1();
        std::vector<Player>& getTeam2();
        std::string positionToString(Position position);
        void decidePinny();

    private:
        std::vector<Player> players;
        std::vector<Player> team1;
        std::vector<Player> team2;
};

#endif // TEAM_H
