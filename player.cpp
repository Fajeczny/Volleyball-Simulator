#include <player.h>
#include <sstream>

Player::Player(std::pair<int,int>newposition, std::string sur, std::string newteam, char sym)
    : position(newposition), surname(sur), team (newteam), symbol(sym)
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
