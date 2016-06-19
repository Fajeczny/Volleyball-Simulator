#ifndef COURT_H
#define COURT_H
#include <vector>
#include <utility>
#include "player.h"
#include "ball.h"
#include "team.h"
#include <array>

class Court
{
    private:
        const int width, height;
        std::vector <std::vector<char> > initialcourt;
        std::vector <std::vector<char> > court;
        std::array <Team,2> clubs;
        Ball ball;
    public:
        friend std::ostream& operator << (std::ostream& output, Court& courtclass);
        Court(int w, int h, Ball ball, std::array<Team,2>& teams);
        void setposition (std::pair<int,int>position, char sym);
        void sortplayers();
        void update();
};

#endif // COURT_H
