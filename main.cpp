#include <iostream>
#include <game.h>
#include <player.h>
using namespace std;


int main()
{
    const int courtheight = 39;
    const int courtwidth = 18;

    Game court(courtheight,courtwidth, {"Asseco Resovia:","Zenit Kazan:"});

    court.addplayer(courtheight/2-13,courtwidth-14,"Fabian Drzyzga","Asseco Resovia",'1');    //usunac nazwy druzyn
    court.addplayer(courtheight/2-4,courtwidth-14,"Thomas Jaeschke","Asseco Resovia",'2');
    court.addplayer(courtheight/2-4,courtwidth-9,"Dmytro Pashytskyy","Asseco Resovia",'3');
    court.addplayer(courtheight/2-4,courtwidth-4,"Bartosz Kurek","Asseco Resovia",'4');
    court.addplayer(courtheight/2-13,courtwidth-4,"Olieg Achrem","Asseco Resovia",'5');
    court.addplayer(courtheight/2-13,courtwidth-9,"Piotr Nowakowski","Asseco Resovia",'6');

    court.addplayer(courtheight/2+13,courtwidth-4,"Maxim Mikhaylov","Zenit Kazan",'1');
    court.addplayer(courtheight/2+4,courtwidth-4,"Matthew Anderson","Zenit Kazan",'2');
    court.addplayer(courtheight/2+4,courtwidth-9,"Andrey Aschev","Zenit Kazan",'3');
    court.addplayer(courtheight/2+4,courtwidth-14,"Aleksandr Butko","Zenit Kazan",'4');
    court.addplayer(courtheight/2+13,courtwidth-14,"Wilfredo Leon","Zenit Kazan",'5');
    court.addplayer(courtheight/2+13,courtwidth-9,"Aleksandr Gutsalyuk","Zenit Kazan",'6');

    court.sortplayers();

    while (true){
        court.update();
    }
}
