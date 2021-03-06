#include "court.h"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>

Court::Court(int w, int h, Ball newball, std::array<Team,2>& teams)
    : width(w), height(h),  clubs(teams), ball(newball)
{
    clubs[0].addplayer({w/2, 4*h/10},"Fabian Drzyzga",'1', 0); //rectangular positions
    clubs[0].addplayer({w/6, h/6},"Bartosz Kurek",'2', 1);
    clubs[0].addplayer({w/6, 4*h/10},"Dmytro Pashytskyy",'3', 2);
    clubs[0].addplayer({5*w/6, 4*h/10},"Thomas Jaeschke",'4', 2);
    clubs[0].addplayer({w/2, h/6},"Olieg Achrem",'5', 1);
    clubs[0].addplayer({5*w/6, h/6},"Krzysztof Ignaczak",'6', 1);

    clubs[1].addplayer({w/2, 6*h/10},"Aleksandr Butko",'1', 0);
    clubs[1].addplayer({5*w/6, 5*h/6},"Maxim Mikhaylov",'2', 1);
    clubs[1].addplayer({5*w/6, 6*h/10},"Andrey Aschev",'3', 2);
    clubs[1].addplayer({w/6, 6*h/10},"Matthew Anderson",'4', 2);
    clubs[1].addplayer({w/2, 5*h/6},"Wilfredo Leon",'5', 1);
    clubs[1].addplayer({w/6, 5*h/6},"Teodor Salparov",'6', 1);

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
    output << courtclass.clubs[0].getname() << "\t      " << courtclass.clubs[0].getpoints();
    output << ":";
    output << courtclass.clubs[1].getpoints() << "\t   " << courtclass.clubs[1].getname() << "\n\n";
    output << "\t" << courtclass.clubs[0].getsets() << "\t\t\t\t" << courtclass.clubs[1].getsets() << "\n\n";
    for(std::size_t i=0; i<courtclass.clubs[0].getplayers().size(); ++i)  //printing teams
    {
        output << (*courtclass.clubs[0].getplayers()[i]) << "\t\t"
                            << (*courtclass.clubs[1].getplayers()[i]) << '\n';
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
            setposition(clubs[j].getplayers()[i]->getposition(), clubs[j].getplayers()[i]->getsymbol());
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
        for (Player *player:team.getplayers())
        {
            player->update();
        }
    }
    ball.update(width, height, clubs, isservice, servingteam);


    usleep(0.05*1000000);        //delay (k*1s)
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
