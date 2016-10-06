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
        std::pair<double, double> real_position;
        std::pair<double, double> real_velocity;
        char symbol;
        int iterations;
        int lastballtouch;
        char pointsymbol;

    public:
        Ball(std::pair<int,int> ballposition, char ballsymbol, std::pair<double, double> speed);

        void update(int courtwidth, int courtheight, std::array<Team,2>& teams, bool &isservice, int &servingteam);

        std::pair<int,int>getposition();

        std::pair<double,double>getrealposition();

        int getiterations();

        void setiterations(int iterations);

        void setposition(std::pair<int,int> position);

        void setrealposition(std::pair<double,double> real_position);

        char getsymbol();

        void setrealvelocity(std::pair<std::pair<double,double>,int> real_velocity);

        void setlastballtouch(int lasttouch);


        void setsymbol(char winningpointsymbol);
};

#endif // BALL_H
