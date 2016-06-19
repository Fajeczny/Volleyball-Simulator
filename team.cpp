#include "team.h"
#include <iostream>

Team::Team(std::string teamname) : name(teamname)
{

}

std::string Team::getname()
{
    return name;
}

std::vector<Player>& Team::getplayers()
{
    return players;
}

void Team::addplayer (std::pair<int,int>position, std::string sur, char sym)
{
    players.push_back(Player(position,sur,name,sym));
}
