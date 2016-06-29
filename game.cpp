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

int Game::gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a < b)
    {
        int tmp;
        tmp = b;
        b = a;
        a = tmp;
    }
    int c;
    while(b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

std::pair<std::pair<int,int>,int> Game::calculatevelocity(std::pair<int,int> begin, std::pair<int,int> end)
{
    std::pair<int,int> shift = {(end.first-begin.first),(end.second-begin.second)};
    int nwd = gcd(shift.first,shift.second);
    shift.first /= nwd;
    shift.second /= nwd;
    return {shift,nwd};
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
//        usleep(1*1000000);
        for(int i=0; i<2; ++i)
        {
            for(Player& player:court.getteam(i).getplayers())
            {
                player.setposition(player.getinitialposition());
                player.setvelocity({{0,0},0});
            }
        }
        std::vector<Player>& players = court.getteam(servingteam).getplayers();

        int min = INT_MAX;
        int servingguyID = 0;
        for (std::size_t i=0; i<players.size(); ++i)
        {
            if (distance(players[i].getposition(),point) < min)
            {
                min = distance(players[i].getposition(),point);
                servingguyID = i;
            }
        }

        players[servingguyID].setposition(std::make_pair(players[servingguyID].getposition().first,servingteam==0 ? 0 : court.getheight()-1));
        court.getball().setposition(players[servingguyID].getposition());

        srand (time(NULL));

        std::pair<int,int> destinationpoint;

        if (servingteam == 0)
        {
            destinationpoint = {(rand()%court.getwidth()/2+2),(rand()%2*court.getheight()/3)+court.getheight()/2};
        }
        else
        {
            destinationpoint = {(rand()%court.getwidth()/2+2),(rand()%2*court.getheight()/3)+(1-court.getheight()/6)};
//            std::cout << destinationpoint.first << "\n\n\n\n\n" << destinationpoint.second << "\n\n\n\n\n";
        }

        players[servingguyID].setvelocity(calculatevelocity(players[servingguyID].getposition(),players[servingguyID].getinitialposition()));
        court.getball().setvelocity(calculatevelocity(players[servingguyID].getposition(),destinationpoint));

        court.getball().setlastballtouch(servingteam);
        isservice = false;
    }

    std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
    court.update(isservice, servingteam);
}

int Game::distance(std::pair<int,int> point1, std::pair<int,int> point2)
{
    int dist = abs((point1.first - point2.first)) + abs((point1.second - point2.second));
    return dist;
}
