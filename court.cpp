#include "court.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unistd.h>

Court::Court(int w, int h, Ball newball) : width(w), height(h), ball(newball)
{
    court.reserve(width);
    for (int i=0; i<width; ++i)
    {
        if (i==width/2) //net
        {
            court.push_back(std::vector<char> (height,'=') );
        }
        else if(i==(width/3)-1 || i==(2*width/3) || i == width-1)   //3rd and 9th meter lines
        {
            court.push_back(std::vector<char> (height,'_') );
        }
        else
        {
            court.push_back(std::vector<char> (height,' ') );
        }
    }
    initialcourt = court;
}

std::ostream& operator << (std::ostream& output, const Court& courtclass)
{
    for(std::size_t i=0; i<courtclass.players.size(); i+=2)  //printing teams
    {
        output << courtclass.players[i] << "\t\t" << courtclass.players[i+1] << '\n';
    }
    output << "\t ";    //indent for 9th meter line
    for (int i=0; i<courtclass.width/2-3; ++i)
    { //upper 9th meter line
        output << ' ' << '_';
    }
    output << std::endl;
    for (int i=0; i<courtclass.width; ++i)
    {
        for (int j=0; j<courtclass.height; ++j)
        {
            if (j==0 && i!=courtclass.width/2)
            {
                output << "\t|" << " ";
            }
            else if (j == courtclass.height-1 && i!=courtclass.width/2)
            {
                output << "|" << " ";
            }
            else if (j==0 && i==courtclass.width/2)
            {
                output << "\t=" << " ";
            }
            else
            {
                output << courtclass.court[i][j] << " ";
            }
        }
        output << std::endl;
    }
    return output;
}

void Court::addplayer (std::pair<int,int>position, std::string sur, std::string newteam, char sym)
{
    players.push_back(Player(position,sur,newteam,sym));
}

void Court::sortplayers()
{
    std::sort(players.begin(),players.end());
}

void Court::setposition (std::pair<int,int>position, char sym)
{
    court[position.first][position.second] = sym;
}

void Court::update ()
{
    court = initialcourt;
    for (std::size_t i=0; i<players.size(); ++i)
    {
        setposition(players[i].getposition(), players[i].getsymbol());
    }
    ball.update();

    if (ball.getposition().first >= 0 && ball.getposition().first < width
            && ball.getposition().second >= 0 && ball.getposition().second < height)
    {
        setposition(ball.getposition(),ball.getsymbol());
    }

    std::cout << *this;     //pointer na obiekt akutalnie uzywany
    usleep(1000000);        //delay (us)
}
