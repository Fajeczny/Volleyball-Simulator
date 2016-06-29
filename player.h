#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "ball.h"
#include "statistics.h"
#include "vposition.h"

class Ball;
class VPosition;
class Player
{
    private:
        std::pair<int,int> position;
        std::pair<int,int> velocity;
        std::string surname;
        std::string team;
        char symbol;
        int iterations;
        std::pair<int,int> initialposition;
        Statistics statistics;
        VPosition* volleyballposition;
    public:
        Player (std::pair<int,int>newposition, std::string sur, std::string newteam, char sym, Statistics newstatistics, VPosition* vposition);
        friend std::ostream& operator << (std::ostream& output, const Player& playerclass);
        friend bool operator < (Player player1, Player player2);
        std::pair<int,int> getposition();
        std::pair<int,int> getvelocity();
        char getsymbol();
        std::string getteam();
        void service(Ball& serviceball);
        void setposition(std::pair<int,int> position);
        void setvelocity(std::pair<std::pair<int,int>,int> velocity);
        void update();
        std::pair<int,int> getinitialposition();
};

#endif // PLAYER_H

