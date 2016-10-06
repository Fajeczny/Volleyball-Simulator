#include "ball.h"
#include <iostream>
#include <unistd.h>

Ball::Ball(std::pair<int,int>ballposition,char ballsymbol,std::pair<double,double>speed={0,0})
    : position(ballposition), real_velocity(speed), symbol(ballsymbol), iterations(0), lastballtouch(0), pointsymbol('P')
{

}

void Ball::update(int courtwidth, int courtheight, std::array<Team,2>& teams, bool& isservice, int &servingteam)
{
    real_position.first+=real_velocity.first;
    real_position.second+=real_velocity.second;
    this->iterations--;
    this->setposition(static_cast<std::pair<int,int>>(this->getrealposition()));

    int i=0;
    for(Team &team:teams)
    {
        if (i == servingteam)
        {
            ++i;
            continue;
        }

        for (Player *player:team.getplayers())
        {
            //Square 3x3
            if ((player->getposition().first        == position.first   && player->getposition().second     == position.second) ||
                (player->getposition().first + 1    == position.first   && player->getposition().second + 1 == position.second) ||
                (player->getposition().first + 1    == position.first   && player->getposition().second     == position.second) ||
                (player->getposition().first        == position.first   && player->getposition().second + 1 == position.second) ||
                (player->getposition().first - 1    == position.first   && player->getposition().second - 1 == position.second) ||
                (player->getposition().first - 1    == position.first   && player->getposition().second     == position.second) ||
                (player->getposition().first        == position.first   && player->getposition().second - 1 == position.second) ||
                (player->getposition().first + 1    == position.first   && player->getposition().second - 1 == position.second) ||
                (player->getposition().first - 1    == position.first   && player->getposition().second + 1 == position.second) ||

                //Plus 1 to the left and 1 to the right
                (player->getposition().first - 2    == position.first   && player->getposition().second     == position.second) ||
                (player->getposition().first + 2    == position.first   && player->getposition().second     == position.second  ))

            //Square 5x5
//            if((player->getposition().first - 2 == position.first  && player->getposition().second - 2 == position.second) ||
//               (player->getposition().first - 1 == position.first  && player->getposition().second - 2 == position.second) ||
//               (player->getposition().first     == position.first  && player->getposition().second - 2 == position.second) ||
//               (player->getposition().first + 1 == position.first  && player->getposition().second - 2 == position.second) ||
//               (player->getposition().first + 2 == position.first  && player->getposition().second - 2 == position.second) ||

//               (player->getposition().first - 2 == position.first  && player->getposition().second - 1 == position.second) ||
//               (player->getposition().first + 2 == position.first  && player->getposition().second - 1 == position.second) ||

//               (player->getposition().first - 2 == position.first  && player->getposition().second     == position.second) ||
//               (player->getposition().first + 2 == position.first  && player->getposition().second     == position.second) ||

//               (player->getposition().first - 2 == position.first  && player->getposition().second + 1 == position.second) ||
//               (player->getposition().first + 2 == position.first  && player->getposition().second + 1 == position.second) ||

//               (player->getposition().first - 2 == position.first  && player->getposition().second + 2 == position.second) ||
//               (player->getposition().first - 1 == position.first  && player->getposition().second + 2 == position.second) ||
//               (player->getposition().first     == position.first  && player->getposition().second + 2 == position.second) ||
//               (player->getposition().first + 1 == position.first  && player->getposition().second + 2 == position.second) ||
//               (player->getposition().first + 2 == position.first  && player->getposition().second + 2 == position.second) )
            {
                std::pair<std::pair<double, double>, int> tmp = player->doaction(teams, i, lastballtouch, servingteam);

                if (tmp.second)
                {
                    lastballtouch = i;
                    tmp.second++;
                    this->setrealvelocity(tmp);
                }
            }
        }
        ++i;
    }

    if(this->iterations == 0){
        if(lastballtouch == 0)
        {
            if(position.first > 0 && position.first < courtwidth && position.second > courtheight/2 && position.second <= courtheight)
            {
                teams[0].setpoints(teams[0].getpoints()+1);
                servingteam = 0;
                setiterations(0);
            }
            else
            {
                teams[1].setpoints(teams[1].getpoints()+1);
                servingteam = 1;
                setiterations(0);
            }
        }
        else
        {
            if(position.first > 0 && position.first < courtwidth && position.second >= 0 && position.second < courtheight/2)
            {
                teams[1].setpoints(teams[1].getpoints()+1);
                servingteam = 1;
                setiterations(0);
            }
            else
            {
                teams[0].setpoints(teams[0].getpoints()+1);
                servingteam = 0;
                setiterations(0);
            }
        }

        if(teams[0].getsets()==2 && teams[1].getsets()==2)
        {
            if(teams[0].getpoints() == 15)
            {
                teams[0].setsets(teams[0].getsets()+1);
            }
            else if(teams[1].getpoints() == 15)
            {
                teams[1].setsets(teams[1].getsets()+1);
            }
        }
        else
        {
            if(teams[0].getpoints() == 25)
            {
                teams[0].setsets(teams[0].getsets()+1);
                usleep(1*1000000);
                teams[0].setpoints(0);
                teams[1].setpoints(0);
            }
            else if(teams[1].getpoints() == 25)
            {
                teams[1].setsets(teams[1].getsets()+1);
                usleep(1*1000000);
                teams[0].setpoints(0);
                teams[1].setpoints(0);
            }
        }

        if (teams[0].getsets()==3)
        {
            std::cout << "\n\t\tWinner: Asseco Resovia!\n\n\n";
            exit(1);
        }
        else if(teams[1].getsets()==3)
        {
            std::cout << "\n\t\tWinner: Zenit Kazan!\n\n\n";
            exit(1);
        }
        usleep(0.5*1000000);

        isservice = true;
    }
}

std::pair<int,int> Ball::getposition()
{
    return position;
}

int Ball::getiterations()
{
    return iterations;
}

void Ball::setiterations(int iterations)
{
    this->iterations = iterations;
}

std::pair<double,double>Ball::getrealposition()
{
    return real_position;
}

char Ball::getsymbol()
{
    return symbol;
}

void Ball::setposition(std::pair<int,int> position)
{
    this->position = position;
}

void Ball::setrealposition(std::pair<double,double> real_position)
{
    this->real_position = real_position;
}

void Ball::setrealvelocity(std::pair<std::pair<double,double>, int> real_velocity)
{
    this->real_velocity = real_velocity.first;
    this->iterations = real_velocity.second;
}

void Ball::setlastballtouch(int lasttouch)
{
    lastballtouch = lasttouch;
}

void Ball::setsymbol(char winningpointsymbol)
{
    symbol = winningpointsymbol;
}
