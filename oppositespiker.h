#ifndef OPPOSITESPIKER_H
#define OPPOSITESPIKER_H
#include "vposition.h"

class OppositeSpiker : public VPosition
{
    public:
        OppositeSpiker();
        void doaction(std::pair<int,int>position, Statistics stats) final;
};

#endif // OPPOSITESPIKER_H
