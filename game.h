#ifndef Game_H
#define Game_H
#include <vector>
#include <iostream>
#include <array>
#include <player.h>

class Game
{
    private:
        const int width, height;
        std::vector <std::vector<char> > court;
        std::vector <Player> players;
        std::array <std::string,2> teams;
        char ball;
    public:
        Game (int w, int h, std::array<std::string, 2> clubs);
        friend std::ostream& operator << (std::ostream& output,const Game& cc);
        void setposition (int x, int y, char sym);
        void addplayer (int d, int s, std::string sur, std::string newteam, char sym);
        void update();
        void sortplayers();
};

#endif // Game_H
