#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "ball.h"

class Team;

class Player
{
    public:
        std::pair<int,int> position;
        std::pair<double, double> real_position;
        std::pair<double, double> real_velocity;
        std::string surname;
        std::string team;
        char symbol;
        std::pair<int,int> initialposition;

    public:
        Player (std::pair<int,int>newposition, std::string sur, std::string newteam, char sym);

        static std::pair<std::pair<double,double>, int> calculaterealvelocity(std::pair<double,double> begin, std::pair<double,double> end);

        virtual std::pair<std::pair<double,double>,int> doaction(std::array<Team,2>& teams, int myside, int last, int &atackteam) = 0;

        friend std::ostream& operator << (std::ostream& output, const Player& playerclass);

        std::pair<int,int> getposition();

        std::pair<double,double>getrealposition();

        char getsymbol();

        std::string getteam();

        void setposition(std::pair<int,int> position);

        void setrealposition(std::pair<double,double> real_position);

        void setrealvelocity(std::pair<std::pair<double,double>, int> real_velocity);

        void update();

        std::pair<int,int> getinitialposition();
};

#endif // PLAYER_H

