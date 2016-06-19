#include "ball.h"

Ball::Ball(std::pair<int,int>ballposition,char ballsymbol,std::pair<int,int>speed={0,0})
    : position(ballposition), velocity(speed), symbol(ballsymbol)
{
}

void Ball::update()
{
    position.first+=velocity.first;
    position.second+=velocity.second;
}

std::pair<int,int> Ball::getposition()
{
    return position;
}

char Ball::getsymbol()
{
    return symbol;
}
