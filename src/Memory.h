#ifndef GUARD_MEMORY
#define GUARD_MEMORY

#include "Pins.h"
#include "Offsets.h"
#include "WorldState.h"

class Memory
{
public:
    static Memory* get();
    void init(unsigned char id);
    char getID();
    Pins* pins;
    Offsets* offsets;
    WorldState* worldState;
private:
    static Memory* instance;
    char id;
};

#endif
