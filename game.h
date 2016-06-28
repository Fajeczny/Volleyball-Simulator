#ifndef Game_H
#define Game_H
#include <vector>
#include <iostream>
#include <array>
#include "player.h"
#include "court.h"
#include "team.h"

class Game
{
    private:
        Court court;
        bool isservice;
    public:
        Game (int w, int h, std::array<Team,2>& clubs);
        friend std::ostream& operator << (std::ostream& output, const Game& gameclass);
        void update();
        int distance(std::pair<int, int> point1, std::pair<int, int> point2);
};

#endif // Game_H
