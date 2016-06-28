#ifndef BALL_H
#define BALL_H
#include <utility>
#include <array>
#include "team.h"

class Team;
class Ball
{
    private:
        std::pair<int,int> position;
        std::pair<int,int> velocity;
        char symbol;
        int iterations;
        int lastballtouch;
    public:
        Ball(std::pair<int,int> ballposition, char ballsymbol, std::pair<int,int> speed);
        void update(int courtwidth, int courtheight, std::array<Team,2>& teams, bool &isservice, int &servingteam);
        void rotate(double angle);
        std::pair<int,int>getposition();
        void setposition(std::pair<int,int> position);
        char getsymbol();
        void setvelocity(std::pair<std::pair<int,int>,int> velocity);
        void setlastballtouch(int lasttouch);
};

#endif // BALL_H
