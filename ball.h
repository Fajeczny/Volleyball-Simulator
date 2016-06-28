#ifndef BALL_H
#define BALL_H
#include <utility>

class Ball
{
    private:
        std::pair<int,int> position;
        std::pair<int,int> velocity;
        char symbol;
    public:
        Ball(std::pair<int,int> ballposition, char ballsymbol, std::pair<int,int> speed);
        void update();
        void rotate(double angle);
        std::pair<int,int>getposition();
        void setposition(std::pair<int,int> position);
        char getsymbol();
        void setvelocity(std::pair<int, int> velocity);
};

#endif // BALL_H
