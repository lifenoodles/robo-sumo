#include "State.h"
#include "WorldState.h"
#include "Memory.h"
#include "SensorsIR.h"
#include "Motors.h"
#include "Behaviour.h"
#include "BlueTooth.h"
#include "Offsets.h"

Maneuver* State::maneuverScan = new
    Maneuver(4,
        (int[]) {MANEUVER_ROTATE_LEFT,
                MANEUVER_ROTATE_RIGHT,
                MANEUVER_ROTATE_LEFT,
                MANEUVER_ROTATE_RIGHT},
        (long[]) {150, 300, 300, 300});

Maneuver* State::maneuverBackup = new
    Maneuver(1,
        (int[]) {MANEUVER_BOTH_BACKWARD},
        (long[]) {300});

Maneuver* State::maneuverRotate = new
    Maneuver(1,
        (int[]) {MANEUVER_ROTATE_LEFT},
        (long[]) {500});

void State::setTimer(long newTime)
{
    timer = newTime;
}

void StateSearch::execute(long delta)
{
    timer += delta;
    bool ir = handleIR(delta);
    bool echoes = false;
    if (!ir)
    {
        echoes = handleEchoes(delta);
    }
    if(!ir && !echoes)
    {
        if (currentManeuver != 0 &&
            !currentManeuver->isDone())
        {
            currentManeuver->execute(delta);
        }
        else
        {
            currentManeuver->reset();
            currentManeuver = 0;
            BlueTooth::get()->logDebug("DEFAULT: ROTATE");
            Motors::get()->rotate(-1);
        }
    }
}

bool StateSearch::handleIR(long delta)
{
    WorldState* worldState = Memory::get()->worldState;
    if (worldState->irSensorsOn[IR_BACK_LEFT]
            && worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("FORWARD");
        Motors::get()->setSpeed(1);
    }
    else if (worldState->irSensorsOn[IR_BACK_LEFT])
    {
        BlueTooth::get()->logDebug("LEFT FORWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
    }
    else if (worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT FORWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT]
        && worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("BACKWARD");
        Motors::get()->setSpeed(-1);
        currentManeuver = State::maneuverBackup;
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT])
    {
        BlueTooth::get()->logDebug("LEFT BACKWARD");
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
        Motors::get()->setSpeed(MOTOR_LEFT, -1);
        currentManeuver = State::maneuverBackup;
    }
    else if (worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT BACKWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
        Motors::get()->setSpeed(MOTOR_RIGHT, -1);
        currentManeuver = State::maneuverBackup;
    }
    else
    {
        return false;
    }
    return true;
}

bool StateSearch::handleEchoes(long delta)
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

void StateChase::execute(long delta)
{
    bool ir = handleIR(delta);
    bool echoes = false;
    if (!ir)
    {
        echoes = handleEchoes(delta);
    }
    if(!ir && !echoes)
    {
        if (currentManeuver != 0 &&
            !currentManeuver->isDone())
        {
            currentManeuver->execute(delta);
        }
        else
        {
            State::maneuverScan->reset();
            Behaviour::get()->stateSearch.currentManeuver
                = State::maneuverScan;

            BlueTooth::get()->logDebug("STATE: SEARCH");
            Behaviour::get()->setState(
                Behaviour::get()->stateSearch);
        }
    }
}

bool StateChase::handleIR(long delta)
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
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
    }
    else if (worldState->irSensorsOn[IR_BACK_RIGHT])
    {
        BlueTooth::get()->logDebug("RIGHT FORWARD");
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    else if (worldState->irSensorsOn[IR_FRONT_LEFT]
        && worldState->irSensorsOn[IR_FRONT_RIGHT])
    {
        State::maneuverBackup->reset();
        Behaviour::get()->stateSearch.currentManeuver
            = State::maneuverBackup;

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
        Motors::get()->setSpeed(MOTOR_RIGHT, 0);
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
    }
    else
    {
        return false;
    }
    return true;
}

bool StateChase::handleEchoes(long delta)
{
    WorldState* worldState = Memory::get()->worldState;
    Offsets* offsets = Memory::get()->offsets;
    timeoutTimer += delta;
    bool isOpponentNear = timeoutTimer <= 200;
    if (timeoutTimer > 200)
        timeoutTimer = 0;
    if (worldState->isOpponentDetected || isOpponentNear)
    {
        BlueTooth::get()->logDebug("CHARGE");
        Motors::get()->setSpeed(1);
        return true;
    }
    return false;
}
