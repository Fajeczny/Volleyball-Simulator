#include "court.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>

Court::Court(int w, int h, Ball newball, std::array<Team,2>& teams)
    : width(w), height(h),  clubs(teams), ball(newball)
{
    clubs[0].addplayer({w/6, h/6},"Fabian Drzyzga",'1');
    clubs[0].addplayer({w/6, 4*h/10},"Thomas Jaeschke",'2');
    clubs[0].addplayer({w/2, 4*h/10},"Dmytro Pashytskyy",'3');
    clubs[0].addplayer({5*w/6, 4*h/10},"Bartosz Kurek",'4');
    clubs[0].addplayer({5*w/6, h/6},"Olieg Achrem",'5');
    clubs[0].addplayer({w/2, h/6},"Piotr Nowakowski",'6');

    clubs[1].addplayer({5*w/6, 5*h/6},"Aleksandr Butko",'1');
    clubs[1].addplayer({5*w/6, 6*h/10},"Matthew Anderson",'2');
    clubs[1].addplayer({w/2, 6*h/10},"Andrey Aschev",'3');
    clubs[1].addplayer({w/6, 6*h/10},"Maxim Mikhaylov",'4');
    clubs[1].addplayer({w/6, 5*h/6},"Wilfredo Leon",'5');
    clubs[1].addplayer({w/2, 5*h/6},"Aleksandr Gutsalyuk",'6');

    court.reserve(width);
    for (int i=0; i<width; ++i)
    {
        court.push_back(std::vector<char> (height,' ') );
        court[i].front() = '-';
        court[i].back() = '-';
        court[i][court[i].size()/2] = '=';
        court[i][court[i].size()/2 + court[i].size()/6] = '-';
        court[i][court[i].size()/2 - court[i].size()/6] = '-';
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

    output << std::endl;
    for (int i=0; i<courtclass.height; ++i)
    {
        for (int j=0; j<courtclass.width; ++j)
        {
            if (j==0)
            {
                output << "\t|" << " ";
            }
            else if (j == courtclass.width-1)
            {
                output << "|" << " ";
            }
            else
            {
                output << courtclass.court[j][i] << " ";
            }
        }
        output << std::endl;
    }
    return output;
}


void Court::sortplayers()
{
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
