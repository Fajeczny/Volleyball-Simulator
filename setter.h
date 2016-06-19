#ifndef SETTER_H
#define SETTER_H
#include "vposition.h"

class Setter : public VPosition
{
    public:
        Setter();
        void doaction(std::pair<int,int>position, Statistics stats) final;
};

#endif // SETTER_H
