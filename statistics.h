#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
    private:
        int defense;
        int block;
        int service;
        int attack;
    public:
        Statistics(int stats[4]);
        int getdefense();
        int getblock();
        int getservice();
        int getattack();
};

#endif // STATISTICS_H
