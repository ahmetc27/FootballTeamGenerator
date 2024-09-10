#include <iostream>

#include "Player.h"
#include "Team.h"
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    Team team;

    team.addPlayer(Player("Spieler 1", 7, MIDFIELD));
    team.addPlayer(Player("Spieler 2", 10, OFFENSIVE));
    team.addPlayer(Player("Spieler 3", 3, DEFENSIVE));
    team.addPlayer(Player("Spieler 4", 6, DEFENSIVE));
    team.addPlayer(Player("Spieler 5", 9, MIDFIELD));
    team.addPlayer(Player("Spieler 6", 8, OFFENSIVE));
    team.addPlayer(Player("Spieler 7", 4, DEFENSIVE));
    team.addPlayer(Player("Spieler 8", 5, MIDFIELD));
    team.addPlayer(Player("Spieler 9", 10, MIDFIELD));
    team.addPlayer(Player("Spieler 10", 2, GOALKEEPER));
    team.addPlayer(Player("Spieler 11", 9, OFFENSIVE));
    team.addPlayer(Player("Spieler 12", 6, GOALKEEPER));
    team.addPlayer(Player("Spieler 13", 1, DEFENSIVE));
    team.addPlayer(Player("Spieler 14", 5, DEFENSIVE));
    team.addPlayer(Player("Spieler 15", 8, DEFENSIVE));
    team.addPlayer(Player("Spieler 16", 3, DEFENSIVE));
    team.addPlayer(Player("Spieler 17", 7, OFFENSIVE));
    team.addPlayer(Player("Spieler 18", 4, OFFENSIVE));
    team.addPlayer(Player("Spieler 19", 6, OFFENSIVE));
    team.addPlayer(Player("Spieler 20", 7, MIDFIELD));
    team.addPlayer(Player("Spieler 21", 2, DEFENSIVE));
    team.addPlayer(Player("Spieler 22", 5, MIDFIELD));


    int input;

    do {
        std::cout << "Choose option to generate teams" << std::endl;
        std::cout << "[1] Random Shuffle with Rating" << std::endl;
        std::cout << "[2] Sort Players with Rating" << std::endl;
        std::cout << "[8] Random Shuffle" << std::endl;
        std::cout << "[9] Sort Players" << std::endl;
        std::cout << "[5] Quit" << std::endl;
        std::cin >> input;
        std::cout << std::endl;

        try {
            switch(input)
            {
            case 1:
                team.shufflePlayers();
                team.createTeams();
                team.decidePinny();
                team.printTeamWithRating(team.getTeam1());
                team.printTeamWithRating(team.getTeam2());
                break;
            case 2:
                team.sortPlayers();
                team.createTeams();
                team.decidePinny();
                team.printTeamWithRating(team.getTeam1());
                team.printTeamWithRating(team.getTeam2());
                break;
            case 8:
                team.shufflePlayers();
                team.createTeams();
                team.printTeam(team.getTeam1());
                team.printTeam(team.getTeam2());

                break;
            case 9:
                team.sortPlayers();
                team.createTeams();
                team.printTeam(team.getTeam1());
                team.printTeam(team.getTeam2());
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid Input" << std::endl;
                continue;
            }
        } catch(const std::logic_error& except) { std::cout << except.what(); }
        catch(...) { std::cout << "Unknown error" << std::endl; }
        std::cout << std::endl;
    } while(input != 5);

    return 0;
}
