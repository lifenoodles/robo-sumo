#include "State.h"
#include "WorldState.h"
#include "Memory.h"
#include "SensorsIR.h"
#include "Motors.h"

void StateSearch::execute(long milliseconds)
{
    Serial.println("IR");
    bool ir = handleIR(milliseconds);
    bool echoes = false;
    if (!ir)
    {
        //EHOES HERE
    }
    if(!ir && !echoes)
    {
        Serial.println("SPINNING!");
        Motors::get()->rotate(1);
    }
}

bool StateSearch::handleIR(long milliseconds)
{
    WorldState* worldState = Memory::get()->worldState;
    //IR CHECKS
    if (worldState->irSensorsOn[IR_BACK_LEFT]
            && worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        Serial.println("FORWARD");
        Motors::get()->setSpeed(1);
    }
    else if (worldState->irSensorsOn[IR_BACK_LEFT])
    {
        Serial.println("LEFT FORWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
    }
    else if (worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        Serial.println("RIGHT FORWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT]
        && worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        Serial.println("BACKWARD");
        Motors::get()->setSpeed(-1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT])
    {
        Serial.println("LEFT BACKWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, -1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        Serial.println("RIGHT BACKWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, -1);
    }
    else
    {
        Motors::get()->rotate(1);
        return false;
    }
    return true;
}

void StateChase::execute(long milliseconds)
{

}

