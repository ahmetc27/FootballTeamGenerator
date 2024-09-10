#include "Team.h"

Team::Team() {}

Team::~Team() {}

void Team::addPlayer(Player&& player) { players.push_back(player); }

void Team::shufflePlayers() { team1.clear(); team2.clear(); std::random_shuffle(players.begin(), players.end()); }

void Team::sortPlayers()
{
    team1.clear();
    team2.clear();

    /*std::sort(players.begin(), players.end(), [](Player& a, Player& b) {
        return a.getRating() < b.getRating();
        });*/

    std::sort(players.begin(), players.end(), [](Player& a, Player& b) {
    if(a.getPosition() == b.getPosition()) {
        return a.getRating() > b.getRating();
    }
    return a.getPosition() < b.getPosition();
});
}

void Team::createTeams()
{
    bool flag = false;
    int countTeam1 = 0;
    int countTeam2 = 0;

    for(int i = 0; i < (int) players.size(); i++)
    {
        if(players[i].getPosition() == GOALKEEPER)
        {
            if(flag == false) { team1.push_back(players[i]); countTeam1++; flag = true; }
            else { team2.push_back(players[i]); countTeam2++; }
        }
        else
        {
            if(i % 2 == 0) { team1.push_back(players[i]); countTeam1++; }
            else { team2.push_back(players[i]); countTeam2++; }
        }
    }
    if(countTeam1 < countTeam2)
    {
        if(team2.back().getPosition() != GOALKEEPER)
        {
            Player lastPlayerOfTeam2 = team2.back();
            team2.pop_back();
            team1.push_back(lastPlayerOfTeam2);
        }
        else
        {
            if(team2.size() < 1) throw std::logic_error("Team 2 too small team size to balance teams");
            int random = rand() % (team2.size() - 1);
            Player randomPlayerOfTeam2 = team2[random];
            team2.erase(team2.begin()+random);
            team1.push_back(randomPlayerOfTeam2);
        }
    }
    else if(countTeam2 < countTeam1)
    {
        if(team1.back().getPosition() != GOALKEEPER)
        {
            Player lastPlayerOfTeam1 = team1.back();
            team1.pop_back();
            team2.push_back(lastPlayerOfTeam1);
        }
        else
        {
            if(team1.size() < 1) throw std::logic_error("Team 1 too small team size to balance teams");
            int random = rand() % (team1.size() - 1);
            Player randomPlayerOfTeam1 = team1[random];
            team1.erase(team1.begin()+random);
            team2.push_back(randomPlayerOfTeam1);
        }
    }

}

void Team::printTeam(std::vector<Player>& team)
{
    for(int i = 0; i < (int) team.size(); i++)
    { std::cout << team[i].getName() << std::endl; }
    std::cout << std::endl;
}

void Team::printTeamWithRating(std::vector<Player>& team)
{
    for(int i = 0; i < (int) team.size(); i++)
    {
        if(team[i].hasPinny() == true)
        {
            std::cout << "[" << i+1 << "] " << team[i].getRating() << " "
            << positionToString(team[i].getPosition()) << " " <<
            team[i].getName() << " (PINNY)" << std::endl;
        }
        else
        {
            std::cout << "[" << i+1 << "] " << team[i].getRating() << " " << positionToString(team[i].getPosition()) << " " <<
            team[i].getName() << std::endl;
        }
    }
    checkScore(team);
    std::cout << std::endl;
}

void Team::checkScore(std::vector<Player>& team)
{
    int result = 0;
    for(int i = 0; i < (int) team.size(); i++) { result += team[i].getRating(); }
    std::cout << "Score: " << result << std::endl;
}
std::vector<Player>& Team::getTeam1() { return team1; }

std::vector<Player>& Team::getTeam2() { return team2; }

std::string Team::positionToString(Position position)
{
    switch(position)
    {
    case DEFENSIVE: return "DEF";
    case OFFENSIVE: return "OFF";
    case MIDFIELD: return "MID";
    case GOALKEEPER: return "TOR";
    default: return "Unknown";
    }
}

void Team::decidePinny()
{
    int randomTeam = rand() % 2 + 1;
    int maxSize = team1.size();
    int randomPlayer = rand() % maxSize;

    if(randomTeam == 1) { team1[randomPlayer].setPinny(true); }
    else { team2[randomPlayer].setPinny(true); }
}
