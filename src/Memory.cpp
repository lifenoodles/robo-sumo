#include "Memory.h"
#include "Consts.h"
#include <Arduino.h>

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
    this->id = id;
    pins = new Pins(id);
    offsets = new Offsets(id);
}

char Memory::getID()
{
    return id;
}
