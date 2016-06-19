#include <iostream>
#include "game.h"
#include "court.h"
#include "player.h"
using namespace std;


int main()
{
    const int courtheight = 39;
    const int courtwidth = 18;

    Game game(courtwidth,courtheight,{"Asseco Resovia","Zenit Kazan"});

    while (true){
        game.update();
    }
}
