#ifndef MIDDLEBLOCKER_H
#define MIDDLEBLOCKER_H
#include "vposition.h"

class MiddleBlocker : public VPosition
{
    public:
        MiddleBlocker();
        void doaction(std::pair<int,int>position, Statistics stats) final;
};

#endif // MIDDLEBLOCKER_H
