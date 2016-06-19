#ifndef COURT_H
#define COURT_H
#include <vector>
#include <utility>
#include "player.h"
#include "ball.h"

class Court
{
    private:
        const int width, height;
        std::vector <std::vector<char> > initialcourt;
        std::vector <std::vector<char> > court;
        std::vector <Player> players;
        Ball ball;
    public:
        friend std::ostream& operator << (std::ostream& output, const Court& courtclass);
        Court(int w, int h, Ball ball);
        void setposition (std::pair<int,int>position, char sym);
        void addplayer (std::pair<int,int>position, std::string sur, std::string newteam, char sym);
        void sortplayers();
        void update();

};

#endif // COURT_H
