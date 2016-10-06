#include "team.h"
#include "setter.h"
#include "receiver.h"
#include "oppositespiker.h"
#include <iostream>

Team::Team(std::string teamname) : points(0), sets(0), name(teamname)
{

}

std::string Team::getname()
{
    return name;
}

std::vector<Player *>& Team::getplayers()
{
    return players;
}

void Team::addplayer (std::pair<int,int>position, std::string sur, char sym, int volleyballposition)
{
    switch (volleyballposition)
    {
        case 0: players.push_back(new Setter(position,sur,name,sym)); break;

        case 1: players.push_back(new Receiver(position,sur,name,sym)); break;

        case 2: players.push_back(new OppositeSpiker(position,sur,name,sym)); break;
    }
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
    points = settingthosepoints;
}

void Team::setsets(int settingthosesets)
{
    sets = settingthosesets;
}

Team::~Team()
{
    for (int i=0; i<players.size(); ++i)
    {
        delete players[i];
    }
}
