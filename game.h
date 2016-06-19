#ifndef Game_H
#define Game_H
#include <vector>
#include <iostream>
#include <array>
#include <player.h>
#include "court.h"

class Game
{
    private:
        std::array <std::string,2> teams;
        Court court;
    public:
        Game (int w, int h, std::array<std::string, 2> clubs);
        friend std::ostream& operator << (std::ostream& output,const Game& gameclass);
        void update();
};

#endif // Game_H
