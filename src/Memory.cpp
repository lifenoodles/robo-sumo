#include "Memory.h"
#include "Consts.h"

Memory* Memory::instance = 0;

Memory* Memory::get()
{
    if (instance == 0)
    {
        instance = new Memory();
    }
    return instance;
}

void Memory::init(unsigned char id)
{
    //set up pins here
}
