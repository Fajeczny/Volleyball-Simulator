#ifndef RECEIVER_H
#define RECEIVER_H
#include "player.h"

class Receiver : public Player
{
    public:
        Receiver(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym);
        virtual std::pair<std::pair<double,double>,int> doaction(std::array<Team,2>& teams, int myside, int last, int &atackteam) final;
};

#endif // RECEIVER_H
