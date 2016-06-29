#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <utility>
#include <vector>
#include "player.h"
#include "statistics.h"
#include "vposition.h"

class Player;
class Team
{
    private:
        int points;
        int sets;
        std::string name;
        std::vector<Player> players;
    public:
        Team(std::string teamname);
        void addplayer (std::pair<int,int> position, std::string sur, char sym, Statistics statistics, VPosition* volleyballposition);
        int getpoints();
        int getsets();
        std::string getname();
        std::vector<Player> &getplayers();
        void setpoints(int settingthosepoints);
        void setsets (int settingthosesets);
};

#endif // TEAM_H
