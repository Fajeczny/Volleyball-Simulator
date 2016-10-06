#ifndef SETTER_H
#define SETTER_H
#include <ctime>
#include <cstdlib>
#include "player.h"

class Setter : public Player
{
    public:
        Setter(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym);

        virtual std::pair<std::pair<double,double>,int> doaction(std::array<Team,2>& teams, int myside, int last, int &atackteam) final;
};

#endif // SETTER_H
