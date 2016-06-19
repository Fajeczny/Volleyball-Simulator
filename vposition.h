#ifndef VPOSITION_H
#define VPOSITION_H
#include <utility>
#include "statistics.h"

class VPosition
{
    public:
        bool defending(std::pair<int,int>position, Statistics stats);
        bool attacking(std::pair<int,int>position, Statistics stats);
        bool blocking(std::pair<int,int>position, Statistics stats);
        bool serving(std::pair<int,int>position, Statistics stats);

        virtual void doaction(std::pair<int,int>position, Statistics stats) =0;
};

#endif // VPOSITION_H
