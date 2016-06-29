#include "court.h"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>

Court::Court(int w, int h, Ball newball, std::array<Team,2>& teams)
    : width(w), height(h),  clubs(teams), ball(newball), oppositespiker(), setter(), middleblocker(), receiver()
{
    clubs[0].addplayer({w/6, 4*h/10},"Fabian Drzyzga",'1',Statistics({0,0,0,4}),&setter); //rectangular positions
    clubs[0].addplayer({w/6, h/6},"Bartosz Kurek",'2',Statistics({80,30,40,0}),&oppositespiker);
    clubs[0].addplayer({w/2, 4*h/10},"Dmytro Pashytskyy",'3',Statistics({80,20,30,0}),&middleblocker);
    clubs[0].addplayer({5*w/6, 4*h/10},"Thomas Jaeschke",'4',Statistics({70,40,60,0}),&receiver);
    clubs[0].addplayer({w/2, h/6},"Olieg Achrem",'5',Statistics({70,70,70,0}),&receiver);
    clubs[0].addplayer({5*w/6, h/6},"Piotr Nowakowski",'6',Statistics({90,10,20,0}),&middleblocker);

    clubs[1].addplayer({5*w/6, 6*h/10},"Aleksandr Butko",'1',Statistics({0,0,0,5}),&setter);
    clubs[1].addplayer({5*w/6, 5*h/6},"Maxim Mikhaylov",'2',Statistics({90,40,50,0}),&oppositespiker);
    clubs[1].addplayer({w/2, 6*h/10},"Andrey Aschev",'3',Statistics({70,20,30,0}),&middleblocker);
    clubs[1].addplayer({w/6, 6*h/10},"Matthew Anderson",'4',Statistics({80,60,80,0}),&receiver);
    clubs[1].addplayer({w/2, 5*h/6},"Wilfredo Leon",'5',Statistics({90,40,50,0}),&receiver);
    clubs[1].addplayer({w/6, 5*h/6},"Aleksandr Gutsalyuk",'6',Statistics({70,10,20,0}),&middleblocker);

    std::string proszetrzy = "  PROSZE TRZY ZERO";
    std::string dajpantrzy = " DAJ PAN TRZY ZERO";
    court.reserve(width);
    for (int i=0; i<width; ++i)
    {
        court.push_back(std::vector<char> (height,' ') );
        court[i].front() = '-';
        court[i].back() = '-';
        court[i][court[i].size()/2] = '=';
//        court[i][court[i].size()/2] = dajpantrzy[i];
//        court[i][court[i].size()/2] = proszetrzy[i];
        court[i][court[i].size()/2 + court[i].size()/6] = '-';
        court[i][court[i].size()/2 - court[i].size()/6] = '-';
    }
    initialcourt = court;
}

std::ostream& operator << (std::ostream& output, Court& courtclass)
{
    output << courtclass.clubs[0].getname() << "\t      " << courtclass.clubs[0].getpoints();
    output << ":";
    output << courtclass.clubs[1].getpoints() << "\t   " << courtclass.clubs[1].getname() << "\n\n";
    output << "\t" << courtclass.clubs[0].getsets() << "\t\t\t\t" << courtclass.clubs[1].getsets() << "\n\n";
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

void Court::setposition (std::pair<int,int> position, char sym)
{
    court[position.first][position.second] = sym;
}

void Court::update (bool& isservice, int &servingteam)
{
    court = initialcourt;
    for (std::size_t j=0; j<clubs.size(); ++j)
    {
        for (std::size_t i=0; i<clubs[j].getplayers().size(); ++i)
        {
            setposition(clubs[j].getplayers()[i].getposition(), clubs[j].getplayers()[i].getsymbol());
        }
    }

    srand (time(NULL));

    if (ball.getposition().first >= 0 && ball.getposition().first < width
            && ball.getposition().second >= 0 && ball.getposition().second < height)
    {
        setposition(ball.getposition(),ball.getsymbol());
    }

    std::cout << *this;    

    for(Team &team:clubs)
    {
        for (Player &player:team.getplayers())
        {
            player.update();
        }
    }
    ball.update(width,height, clubs, isservice, servingteam);


    usleep(0.1*1000000);        //delay (k*1s)
}

Team& Court::getteam(int teamID)
{
    return clubs[teamID];
}

Ball& Court::getball()
{
    return ball;
}

int Court::getwidth()
{
    return width;
}

int Court::getheight()
{
    return height;
}
