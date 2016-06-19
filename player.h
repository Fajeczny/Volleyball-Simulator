#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    private:
        std::pair<int,int>position;
        std::string surname;
        std::string team;
        char symbol;
    public:
        Player (std::pair<int,int>newposition, std::string sur, std::string newteam, char sym);
        friend std::ostream& operator << (std::ostream& os,const Player& cc);
        friend bool operator < (Player player1, Player player2);
        std::pair<int,int>getposition();
        char getsymbol();
        std::string getteam();
};

#endif // PLAYER_H

