#include <iostream>
#include <array>
#include "game.h"
#include "court.h"
#include "player.h"
using namespace std;


int main()
{
    const int courtheight = 39;
    const int courtwidth = 19;
    std::array<Team,2> teams ={Team("Asseco Resovia"),Team("Zenit Kazan")};

    Game game(courtwidth,courtheight,teams);

    while (true){
        game.update();
    }
    return 0;
}
