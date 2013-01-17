#include "Behaviour.h"
#include "Consts.h"
#include "Memory.h"
#include "SensorsIR.h"
#include "Motors.h"

Behaviour* Behaviour::instance = 0;

Behaviour::Behaviour()
{
    sensorReader = new SensorReader();
}

void Behaviour::update(long milliseconds)
{
    WorldState* worldState = Memory::get()->worldState;
    sensorReader->update(milliseconds);
    if (Memory::get()->isRemoteControlled)
    {
        //todo: Cathal
    }
    else
    {
        if (worldState->irSensorsOn[IR_BACK_LEFT]
            || worldState->irSensorsOn[IR_BACK_RIGHT])
        {
            Motors::get()->setSpeed(1);
        }
        else
        {
            Motors::get()->setSpeed(-1);
        }
    }
}

Behaviour* Behaviour::get()
{
    if (instance == 0)
    {
        instance = new Behaviour();
    }
    return instance;
}
