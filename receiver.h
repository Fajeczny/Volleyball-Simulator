#ifndef RECEIVER_H
#define RECEIVER_H
#include "vposition.h"

class Receiver : public VPosition
{
    public:
        Receiver();
        void doaction(std::pair<int,int>position, Statistics stats) final;
};

#endif // RECEIVER_H
