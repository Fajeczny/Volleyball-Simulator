#include <iostream>
#include "receiver.h"

Receiver::Receiver(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym)
                  :Player(newposition, sur, newteam, sym)
{
}

std::pair<std::pair<double, double>, int> Receiver::doaction(std::array<Team, 2> &teams, int myside, int last, int &atackteam)
{
    if (last == myside)
    {
        return {{0,0},0};
    }
    else
    {
        std::vector<Player*> & players = teams[myside].getplayers();
        return Player::calculaterealvelocity(this->getrealposition(), players[0]->getinitialposition());    //Pass to setter
    }

}
