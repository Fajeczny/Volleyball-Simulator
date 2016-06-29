#ifndef STATISTICS_H
#define STATISTICS_H
#include <array>

class Statistics
{
    private:
        int attack;
        int defense;
        int receive;
        int setting;
    public:
        Statistics(std::array<int,4> statistics);
        int getattack();
        int getdefense();
        int getreceive();
        int getsetting();
};

#endif // STATISTICS_H
