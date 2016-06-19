#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    private:
        int x,y;
        std::string surname;
        std::string team;
        char symbol;
        void defense(int def);
        void receive(int rec);
        void block(int blo);
        void attack (int att);
        void service (int ser);
        void setting (int set);
    public:
        Player (int d, int s, std::string sur, std::string newteam, char sym);
        friend std::ostream& operator << (std::ostream& os,const Player& cc);
        friend bool operator < (Player player1, Player player2);
        int getx();
        int gety();
        char getsymbol();
        std::string getteam();
};

#endif // PLAYER_H

