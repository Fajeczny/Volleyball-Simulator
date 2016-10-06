#include "player.h"
#include <sstream>
#include <iostream>
#include <algorithm>

Player::Player(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym)
    : position(newposition), surname(sur), team (newteam), symbol(sym), initialposition(newposition)
{
}

std::pair<int,int>Player::getposition()
{
    return position;
}

std::pair<double,double>Player::getrealposition()
{
    return real_position;
}

char Player::getsymbol()
{
    return symbol;
}

std::string Player::getteam()
{
    return team;
}

std::ostream& operator << (std::ostream& output, const Player& playerclass)
{
    std::stringstream playerprinting;
    playerprinting << playerclass.symbol;
    output << playerprinting.str() << " " << playerclass.surname;
    if (playerclass.surname.size()<14)
    {
        output << '\t';
    }
    return output;
}

void Player::setposition(std::pair<int,int> position)
{
    this->position = position;
}

void Player::setrealposition(std::pair<double,double> real_position)
{
    this->real_position = real_position;
}

void Player::setrealvelocity(std::pair<std::pair<double, double>, int> real_velocity)
{
    this->real_velocity = real_velocity.first;
}

void Player::update()
{
    if (this->getposition() == this->getinitialposition())
    {
        real_velocity.first = 0;
        real_velocity.second = 0;
    }

    real_position.first+=real_velocity.first;
    real_position.second+=real_velocity.second;

    this->setposition(static_cast<std::pair<double,double>>(this->getrealposition()));
}

std::pair<int,int> Player::getinitialposition()
{
    return initialposition;
}

std::pair<std::pair<double,double>,int> Player::doaction(std::array<Team,2>& teams, int myside, int last, int &atackteam)
{
    return {{0,0}, 0};
}

std::pair<std::pair<double,double>, int> Player::calculaterealvelocity(std::pair<double,double> begin, std::pair<double,double> end)
{
    std::pair<double,double> vector = {(end.first-begin.first),(end.second-begin.second)};
    double devider = pow((vector.first*vector.first)+(vector.second*vector.second),0.5);
    vector.first /= devider;
    vector.second /= devider;

    return {vector,static_cast<int>(devider)};
}
