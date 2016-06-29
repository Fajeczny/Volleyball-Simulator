#include <player.h>
#include <sstream>
#include <iostream>

Player::Player(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym, Statistics newstatistics, VPosition* vposition)
    : position(newposition), surname(sur), team (newteam), symbol(sym), iterations(0),
      initialposition(newposition), statistics(newstatistics), volleyballposition(vposition)
{

}

std::pair<int,int>Player::getposition()
{
    return position;
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

bool operator < (Player player1, Player player2)
{
    std::stringstream firstteam;
    std::stringstream secondteam;
    firstteam << player1.symbol << player1.team;
    secondteam << player2.symbol << player2.team;
    return firstteam.str()<secondteam.str();
}

void Player::service(Ball& serviceball)
{

}

void Player::setposition(std::pair<int,int> position)
{
    this->position = position;
}

std::pair<int,int>Player::getvelocity()
{
    return velocity;
}

void Player::setvelocity(std::pair<std::pair<int,int>,int> velocity)
{
    this->velocity = velocity.first;
    iterations = abs(velocity.second);
}

void Player::update()
{
    volleyballposition->doaction(position,statistics);

    if(iterations>0)
    {
        position.first+=velocity.first;
        position.second+=velocity.second;
        --iterations;
    }
}

std::pair<int,int> Player::getinitialposition()
{
    return initialposition;
}
