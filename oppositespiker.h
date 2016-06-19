#ifndef OPPOSITESPIKER_H
#define OPPOSITESPIKER_H
#include <player.h>

class OppositeSpiker : public Player
{
    public:
        void attack (int att);
        OppositeSpiker();
};

#endif // OPPOSITESPIKER_H
