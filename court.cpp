#include "court.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>

Court::Court(int w, int h, Ball newball, std::array<Team,2>& teams)
    : width(w), height(h),  clubs(teams), ball(newball)
{
    clubs[0].addplayer({w-14, h/2-13},"Fabian Drzyzga",'1');
    clubs[0].addplayer({w-14, h/2-4},"Thomas Jaeschke",'2');
    clubs[0].addplayer({w-9, h/2-4},"Dmytro Pashytskyy",'3');
    clubs[0].addplayer({w-4, h/2-4},"Bartosz Kurek",'4');
    clubs[0].addplayer({w-4, h/2-13},"Olieg Achrem",'5');
    clubs[0].addplayer({w-9, h/2-13},"Piotr Nowakowski",'6');

    clubs[1].addplayer({w-4, h/2+13},"Maxim Mikhaylov",'1');
    clubs[1].addplayer({w-4, h/2+4},"Matthew Anderson",'2');
    clubs[1].addplayer({w-9, h/2+4},"Andrey Aschev",'3');
    clubs[1].addplayer({w-14, h/2+4},"Aleksandr Butko",'4');
    clubs[1].addplayer({w-14, h/2+13},"Wilfredo Leon",'5');
    clubs[1].addplayer({w-9, h/2+13},"Aleksandr Gutsalyuk",'6');

    court.reserve(width);
    for (int i=0; i<width; ++i)
    {
//        if (i==width/2) //net
//        {
//            court.push_back(std::vector<char> (height,'=') );
//        }
//        else if(i==(width/3)-1 || i==(2*width/3) || i == width-1)   //3rd and 9th meter lines
//        {
//            court.push_back(std::vector<char> (height,'_') );
//        }
//        else
//        {
            court.push_back(std::vector<char> (height,' ') );
//        }
    }
    initialcourt = court;
}

std::ostream& operator << (std::ostream& output, Court& courtclass)
{
    output << courtclass.clubs[0].getname() << "\t\t\t" << courtclass.clubs[1].getname() << "\n\n";
    for(std::size_t i=0; i<courtclass.clubs[0].getplayers().size(); ++i)  //printing teams
    {
        output << courtclass.clubs[0].getplayers()[i] << "\t\t"
                            << courtclass.clubs[1].getplayers()[i] << '\n';
    }
    output << "\t ";    //indent for 9th meter line
//    for (int i=0; i<courtclass.width/2-3; ++i)
//    { //upper 9th meter line
//        output << ' ' << '_';
//    }
    output << std::endl;
    for (int i=0; i<courtclass.height; ++i)
    {
        for (int j=0; j<courtclass.width; ++j)
        {
//            if (j==0 && i!=courtclass.width/2)
//            {
//                output << "\t|" << " ";
//            }
//            else if (j == courtclass.height-1 && i!=courtclass.width/2)
//            {
//                output << "|" << " ";
//            }
//            else if (j==0 && i==courtclass.width/2)
//            {
//                output << "\t=" << " ";
//            }
//            else
//            {
                output << courtclass.court[j][i] << " ";
//            }
        }
        output << std::endl;
    }
    return output;
}


void Court::sortplayers()
{
//    std::sort(players.begin(),players.end());
}

void Court::setposition (std::pair<int,int>position, char sym)
{
    court[position.first][position.second] = sym;
}

void Court::update ()
{
    court = initialcourt;
    for (std::size_t j=0; j<clubs.size(); ++j)
    {
        for (std::size_t i=0; i<clubs[j].getplayers().size(); ++i)
        {
            //std::cout << clubs[j].getplayers()[i].getposition().first << "  " << clubs[j].getplayers()[i].getposition().second << "\n";
            setposition(clubs[j].getplayers()[i].getposition(), clubs[j].getplayers()[i].getsymbol());
        }
    }
    ball.update();

    if (ball.getposition().first >= 0 && ball.getposition().first < width
            && ball.getposition().second >= 0 && ball.getposition().second < height)
    {
        setposition(ball.getposition(),ball.getsymbol());
    }

    std::cout << *this;
    usleep(0.1*1000000);        //delay (us)
}
