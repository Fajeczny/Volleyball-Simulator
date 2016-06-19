#include <player.h>
#include <sstream>

Player::Player(int d, int s, std::string sur, std::string newteam, char sym)
    : x(d), y(s), surname(sur), team (newteam), symbol(sym)
{
}

int Player::getx()
{
    return x;
}

int Player::gety()
{
    return y;
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
