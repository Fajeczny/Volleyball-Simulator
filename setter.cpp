#include <iostream>
#include "setter.h"

Setter::Setter(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym)
                  :Player(newposition, sur, newteam, sym)
{
}

std::pair<std::pair<double, double>, int> Setter::doaction(std::array<Team, 2> &teams, int myside, int last, int &atackteam)
{
    if (last != myside)
    {
        return {{0,0},0};
    }
    else
    {
        std::vector<Player*> & players = teams[myside].getplayers();

        int number = 0;

        srand(time(NULL));
        number = rand()%2 + 1;

        switch(number)
        {
            //Pass to spiker 3
            case 1: return Player::calculaterealvelocity(this->getrealposition(), players[2]->getinitialposition()); break;

            //Pass to spiker 4
            case 2: return Player::calculaterealvelocity(this->getrealposition(), players[3]->getinitialposition());  break;
        }
    }
}
