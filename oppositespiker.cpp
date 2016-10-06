#include "oppositespiker.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>

OppositeSpiker::OppositeSpiker(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym)
    :Player(newposition, sur, newteam, sym)
{
}

std::pair<std::pair<double, double>, int> OppositeSpiker::doaction(std::array<Team, 2> &teams, int myside, int last, int &atackteam)
{
    if (last != myside)
    {
        return {{0,0},0};
    }
    else
    {
        atackteam = myside;

        srand (time(NULL));

        std::pair<int,int> destinationpoint;

        if (myside == 0)
        {
            destinationpoint = std::make_pair(this->getposition().first + rand()%10 - 5, this->getposition().second + rand()%25+10);
        }
        else
        {
            destinationpoint = std::make_pair(this->getposition().first + rand()%10 - 5, this->getposition().second - (rand()%25+10));
        }

        return Player::calculaterealvelocity(this->getrealposition(), destinationpoint); //Spike
    }
}
