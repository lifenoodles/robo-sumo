#include "State.h"
#include "WorldState.h"
#include "Memory.h"
#include "SensorsIR.h"
#include "Motors.h"
#include "Behaviour.h"
#include "BlueTooth.h"
#include "Offsets.h"

void StateSearch::execute(long milliseconds)
{
    bool ir = handleIR(milliseconds);
    bool echoes = false;
    if (!ir)
    {
        handleEchoes(milliseconds);
    }
    if(!ir && !echoes)
    {
        BlueTooth::get()->logDebug("ROTATE");
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
        BlueTooth::get()->logDebug("FORWARD");
        Motors::get()->setSpeed(1);
    }
    else if (worldState->irSensorsOn[IR_BACK_LEFT])
    {
        BlueTooth::get()->logDebug("LEFT FORWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
    }
    else if (worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT FORWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT]
        && worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("BACKWARD");
        Motors::get()->setSpeed(-1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT])
    {
        BlueTooth::get()->logDebug("LEFT BACKWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, -1);
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
    }
    else if (worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT BACKWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, -1);
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
    }
    else
    {
        return false;
    }
    return true;
}

bool StateSearch::handleEchoes(long milliseconds)
{
    if (Memory::get()->worldState->isOpponentDetected)
    {
        BlueTooth::get()->logDebug("STATE: CHASE");
        Behaviour::get()->setState(
            Behaviour::get()->stateChase);
        return true;
    }
    return false;
}

void StateChase::execute(long milliseconds)
{
    bool ir = handleIR(milliseconds);
    bool echoes = false;
    if (!ir)
    {
        handleEchoes(milliseconds);
    }
    if(!ir && !echoes)
    {
        BlueTooth::get()->logDebug("STATE: SEARCH");
        Behaviour::get()->setState(
            Behaviour::get()->stateSearch);
    }
}

bool StateChase::handleIR(long milliseconds)
{
    WorldState* worldState = Memory::get()->worldState;
    //IR CHECKS
    if (worldState->irSensorsOn[IR_BACK_LEFT]
            && worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("FORWARD");
        Motors::get()->setSpeed(1);
    }
    else if (worldState->irSensorsOn[IR_BACK_LEFT])
    {
        BlueTooth::get()->logDebug("LEFT FORWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
    }
    else if (worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT FORWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT]
        && worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("STATE: SEARCH");
        Motors::get()->stop();
        Behaviour::get()->setState(
            Behaviour::get()->stateSearch);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT])
    {
        BlueTooth::get()->logDebug("FINISH RIGHT");
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("FINISH LEFT");
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
    }
    else
    {
        return false;
    }
    return true;
}

bool StateChase::handleEchoes(long milliseconds)
{
    WorldState* worldState = Memory::get()->worldState;
    Offsets* offsets = Memory::get()->offsets;
    if (worldState->isOpponentDetected)
    {
        BlueTooth::get()->logDebug("CHARGE");
        Motors::get()->setSpeed(1);
        return true;
    }
    return false;
}

