#include "Behaviour.h"
#include "Consts.h"
#include "Memory.h"
#include "SensorsIR.h"
#include "Motors.h"
#include <Arduino.h>

Behaviour* Behaviour::instance = 0;

Behaviour::Behaviour()
{
    sensorReader = new SensorReader();
    currentState = &stateSearch;
}

void Behaviour::update(long milliseconds)
{
    sensorReader->update(milliseconds);
    WorldState* worldState = Memory::get()->worldState;
    if (Memory::get()->isRemoteControlled)
    {
        while (Serial.available() > 0)
        {
            char command = Serial.read();
            char arg = Serial.read();
            if(command == 'l')
            {
                Motors::get()->setSpeed(MOTOR_LEFT, arg);
            }
            else if(command == 'r')
            {
                Motors::get()->setSpeed(MOTOR_RIGHT, arg);
            }
            Serial.print(command);
            Serial.print("\t");
            Serial.print(arg);
        }
    }
    else
    {
        currentState->execute(milliseconds);
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
