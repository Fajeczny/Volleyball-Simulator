#include "game.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <sstream>
#include <climits>

Game::Game (int w, int h, std::array <Team,2>& clubs)
    : court(w,h,Ball({3,0},'@',{0,0}),clubs), isservice(true), servingteam(0)

{

}

void Game::update()
{
    std::pair<int,int> point = {court.getwidth(),court.getheight()};
         if (servingteam == 0)
         {
             point= {0,0};
         }
    if(isservice == true)   //while serving
    {
        for(int i=0; i<2; ++i)
        {
            for(Player *player:court.getteam(i).getplayers())
            {
                player->setposition(player->getinitialposition());
                player->setrealposition(static_cast<std::pair<double, double>>(player->getinitialposition()));
                player->setrealvelocity({{0,0},0});
            }
        }
        std::vector<Player*> players = court.getteam(servingteam).getplayers();

        int min = INT_MAX;
        int servingguyID = 0;
        for (std::size_t i=0; i<players.size(); ++i)
        {
            if (distance(players[i]->getposition(),point) < min)
            {
                min = distance(players[i]->getposition(),point);
                servingguyID = i;
            }
        }

        players[servingguyID]->setposition(std::make_pair(players[servingguyID]->getposition().first,servingteam==0 ? 0 : court.getheight()-1));
        players[servingguyID]->setrealposition(static_cast<std::pair<double, double>>(std::make_pair(players[servingguyID]->getposition().first,servingteam==0 ? 0 : court.getheight()-1)));
        court.getball().setposition(players[servingguyID]->getposition());
        court.getball().setrealposition(static_cast<std::pair<double, double>>(players[servingguyID]->getposition()));

        srand (time(NULL));

        std::pair<int,int> destinationpoint;

        if (servingteam == 0)
        {
            destinationpoint = {(rand()%court.getwidth()/2+2),rand()%court.getheight()+3*court.getheight()/4};
        }
        else
        {
            destinationpoint = {(rand()%court.getwidth()/2+2),rand()%(court.getheight()/4) + 0};
        }

        players[servingguyID]->setrealvelocity(Player::calculaterealvelocity(players[servingguyID]->getrealposition(), static_cast<std::pair<double, double>>(players[servingguyID]->getinitialposition())));
        court.getball().setrealvelocity(Player::calculaterealvelocity(players[servingguyID]->getrealposition(), static_cast<std::pair<double, double>>(destinationpoint)));

        court.getball().setlastballtouch(servingteam);
        isservice = false;
    }

    while (court.getball().getiterations())
    {
        std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
        court.update(isservice, servingteam);
    }
}

int Game::distance(std::pair<int,int> point1, std::pair<int,int> point2)
{
    int dist = abs((point1.first - point2.first)) + abs((point1.second - point2.second));
    return dist;
}
