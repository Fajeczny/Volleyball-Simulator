#include "team.h"
#include <iostream>

Team::Team(std::string teamname) : points(0), sets(0), name(teamname)
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

int Team::getpoints()
{
    return points;
}

int Team::getsets()
{
    return sets;
}

void Team::setpoints(int settingthosepoints)
{
    this->points = settingthosepoints;
}
