#include "Behaviour.h"
#include "Consts.h"

Behaviour* Behaviour::instance = 0;

Behaviour::Behaviour()
{

}

void Behaviour::update(long milliseconds)
{

}

Behaviour* Behaviour::get()
{
    if (instance == 0)
    {
        instance = new Behaviour();
    }
    return instance;
}
