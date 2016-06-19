#include "game.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <sstream>

Game::Game (int w, int h, std::array <Team,2>& clubs)
    : court(w,h,Ball({0,0},'@',{1,1}),clubs)
{
    court.sortplayers();
}

void Game::update()
{
    std::cout << "\033[2J\033[1;1H";    //clearing terminal in Linux
    court.update();
}
