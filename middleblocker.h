#ifndef MIDDLEBLOCKER_H
#define MIDDLEBLOCKER_H
#include <player.h>

class MiddleBlocker : public Player
{
    public:
        void attack (int att);
        MiddleBlocker();
};

#endif // MIDDLEBLOCKER_H
