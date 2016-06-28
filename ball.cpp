#include "ball.h"
#include <iostream>

Ball::Ball(std::pair<int,int>ballposition,char ballsymbol,std::pair<int,int>speed={0,0})
    : position(ballposition), velocity(speed), symbol(ballsymbol), iterations(0), lastballtouch(0)
{

}

void Ball::update(int courtwidth, int courtheight, std::array<Team,2>& teams, bool& isservice, int &servingteam)
{
    if(iterations>0)
    {
        position.first+=velocity.first;
        position.second+=velocity.second;
        --iterations;
    }
    else
    {
        if(lastballtouch == 0)
        {
            if(position.first > 0 && position.first < courtwidth && position.second > courtheight/2 && position.second < courtheight)
            {
                teams[0].setpoints(teams[0].getpoints()+1);
                servingteam = 0;
            }
            else
            {
                teams[1].setpoints(teams[1].getpoints()+1);
                servingteam = 1;
            }
        }
        else
        {
            if(position.first > 0 && position.first < courtwidth && position.second >0 && position.second < courtheight/2)
            {
                teams[1].setpoints(teams[1].getpoints()+1);
                servingteam = 1;
            }
            else
            {
                teams[0].setpoints(teams[0].getpoints()+1);
                servingteam = 0;
            }
        }
        isservice = true;
    }
}

std::pair<int,int> Ball::getposition()
{
    return position;
}

char Ball::getsymbol()
{
    return symbol;
}

void Ball::setposition(std::pair<int,int> position)
{
    this->position = position;
}

void Ball::setvelocity(std::pair<std::pair<int,int>,int> velocity)
{
    this->velocity = velocity.first;
    iterations = velocity.second;
}

void Ball::setlastballtouch(int lasttouch)
{
    lastballtouch = lasttouch;
}
