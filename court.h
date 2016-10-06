#ifndef COURT_H
#define COURT_H
#include <vector>
#include <utility>
#include <array>
#include "player.h"
#include "ball.h"
#include "team.h"
#include "oppositespiker.h"
#include "setter.h"
#include "receiver.h"

class Court
{
    private:
        const int width, height;
        std::vector <std::vector<char>> initialcourt;
        std::vector <std::vector<char>> court;
        std::array <Team,2> clubs;
        Ball ball;

    public:
        Court(int w, int h, Ball ball, std::array<Team,2>& teams);
        friend std::ostream& operator << (std::ostream& output, Court& courtclass);
        void setposition (std::pair<int,int> position, char sym);
        void update(bool &isservice, int &servingteam);
        Team& getteam(int teamID);
        Ball& getball();
        int getwidth();
        int getheight();
};

#endif // COURT_H
