#ifndef Game_H
#define Game_H
#include <vector>
#include <iostream>
#include <array>

#include "court.h"

class Game
{
    private:
        Court court;
        bool isservice;
        int servingteam;
    public:
        Game (int w, int h, std::array<Team,2>& clubs);
        friend std::ostream& operator << (std::ostream& output, const Game& gameclass);
        void update();
        int distance(std::pair<int, int> point1, std::pair<int, int> point2);
        int gcd(int a,int b);
        std::pair<std::pair<int,int>,int> calculatevelocity(std::pair<int,int> begin, std::pair<int,int> end);
        int getwidth();
        int getheight();
};

#endif // Game_H
