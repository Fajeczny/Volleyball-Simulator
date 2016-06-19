#include <game.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <sstream>
#include "court.h"

Game::Game (int w, int h, std::array <std::string,2> clubs)
    : teams(clubs),court(h,w,Ball({0,0},'.',{1,1}))
{
    court.addplayer({h/2-13,w-14},"Fabian Drzyzga",teams[0],'1');  //usunac nazwy druzyn
    court.addplayer({h/2-4,w-14},"Thomas Jaeschke",teams[0],'2');
    court.addplayer({h/2-4,w-9},"Dmytro Pashytskyy",teams[0],'3');
    court.addplayer({h/2-4,w-4},"Bartosz Kurek",teams[0],'4');
    court.addplayer({h/2-13,w-4},"Olieg Achrem",teams[0],'5');
    court.addplayer({h/2-13,w-9},"Piotr Nowakowski",teams[0],'6');

    court.addplayer({h/2+13,w-4},"Maxim Mikhaylov",teams[1],'1');
    court.addplayer({h/2+4,w-4},"Matthew Anderson",teams[1],'2');
    court.addplayer({h/2+4,w-9},"Andrey Aschev",teams[1],'3');
    court.addplayer({h/2+4,w-14},"Aleksandr Butko",teams[1],'4');
    court.addplayer({h/2+13,w-14},"Wilfredo Leon",teams[1],'5');
    court.addplayer({h/2+13,w-9},"Aleksandr Gutsalyuk",teams[1],'6');

    court.sortplayers();
}


std::ostream& operator << (std::ostream& output, const Game& gameclass)
{
    output << gameclass.teams[0] << "\t\t\t" << gameclass.teams[1] << "\n\n";
    return output;
}

void Game::update()
{
    std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
    std::cout << *this;
    court.update();
}
