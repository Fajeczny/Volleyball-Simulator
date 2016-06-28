#include "game.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <sstream>

Game::Game (int w, int h, std::array <Team,2>& clubs)
    : court(w,h,Ball({3,0},'@',{0,0}),clubs), isservice(true)
{

}

void Game::update()
{
    if(isservice == true)
    {
        court.getteam(0);
        std::vector<Player>& players = court.getteam(0).getplayers();

        int min = distance(players[0].getposition(),{0,0});
        int servingguyID = 0;
        for (std::size_t i=0; i<players.size(); ++i)
        {
            if (distance(players[i].getposition(),{0,0}) < min)
            {
                min = distance(players[i].getposition(),{0,0});
                servingguyID = i;
            }
        }

        players[servingguyID].setposition(std::make_pair(players[servingguyID].getposition().first,0));
        court.getball().setposition(players[servingguyID].getposition());

        srand (time(NULL));

        court.getball().setvelocity({rand()%4-1,rand()%5+3});

        isservice = false;
    }

    std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
    court.update();
}

int Game::distance(std::pair<int,int> point1, std::pair<int,int> point2)
{
    int dist = (point1.first - point2.first) + (point1.second - point2.second);
    return dist;
}
