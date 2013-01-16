#ifndef GUARD_MEMORY
#define GUARD_MEMORY

#include "Pins.h"

class Memory
{
public:
    static Memory* get();
    void init(unsigned char id);
    char getID();
    Pins* pins;
private:
    static Memory* instance;
    char id;
};

#endif
