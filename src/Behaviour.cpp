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

void Behaviour::update(long delta)
{
    sensorReader->update(delta);
    WorldState* worldState = Memory::get()->worldState;
    if (Memory::get()->isRemoteControlled)
    {
        if (Serial.available() >= 2)
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
        currentState->execute(delta);
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

void Behaviour::setState(State& state)
{
    currentState = &state;
}
