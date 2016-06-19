#ifndef RECEIVER_H
#define RECEIVER_H
#include <player.h>

class Receiver : public Player
{
    public:
        void receive(int rec);
        void attack (int att);
        Receiver();
};

#endif // RECEIVER_H
