#ifndef VPOSITION_H
#define VPOSITION_H
#include <utility>
#include "statistics.h"

class VPosition
{
    public:
        VPosition();
        bool attacking(std::pair<int,int> position, Statistics stats);
        bool defending(std::pair<int,int> position, Statistics stats);
        bool receiving(std::pair<int,int> position, Statistics stats);
        bool setting(std::pair<int,int> position, Statistics stats);

        virtual void doaction(std::pair<int,int>position, Statistics stats) =0;
};

#endif // VPOSITION_H
