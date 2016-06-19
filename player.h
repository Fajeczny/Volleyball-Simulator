#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    protected:
        int x,y;
        std::string surname;
        std::string team;
        char symbol;
    public:
        void defense(int def);
        void block(int blo);
        void service (int ser);
        Player (int d, int s, std::string sur, std::string newteam, char sym);
        friend std::ostream& operator << (std::ostream& os,const Player& cc);
        friend bool operator < (Player player1, Player player2);
        int getx();
        int gety();
        char getsymbol();
        std::string getteam();
};

#endif // PLAYER_H

