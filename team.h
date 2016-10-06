#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <utility>
#include <vector>
#include "player.h"

class Player;

class Team
{
    private:
        int points;
        int sets;
        std::string name;
        std::vector<Player *> players;

    public:
        ~Team();

        Team(std::string teamname);
        void addplayer (std::pair<int,int> position, std::string sur, char sym, int volleyballposition);

        int getpoints();

        int getsets();

        std::string getname();
        std::vector<Player *> &getplayers();

        void setpoints(int settingthosepoints);

        void setsets (int settingthosesets);
};

#endif // TEAM_H
