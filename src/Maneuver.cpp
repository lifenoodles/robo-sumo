#include "Maneuver.h"
#include "Motors.h"
#include "BlueTooth.h"

Maneuver::Maneuver(int moveCount,
    int moveArray[], long timeArray[])
{
    this->moveCount = moveCount;
    moveTimer = 0;
    moveIndex = 0;
    moves = moveArray;
    times = timeArray;
}

void Maneuver::execute(long delta)
{
    moveTimer += delta;
    while (!isDone() && moveTimer > times[moveIndex])
    {
        moveTimer -= times[moveIndex];
        ++moveIndex;
    }
    if (!isDone())
    {
        moveMotor(moves[moveIndex]);
    }
}

bool Maneuver::isDone()
{
    return moveIndex >= moveCount;
}

void Maneuver::reset()
{
    moveIndex = 0;
    moveTimer = 0;
}

void Maneuver::moveMotor(int moveId)
{
    switch (moveId)
    {
        case MANEUVER_LEFT_FORWARD:
            BlueTooth::get()->logDebug("MANEUVER_LEFT_FORWARD");
            Motors::get()->setSpeed(MOTOR_RIGHT, 0);
            Motors::get()->setSpeed(MOTOR_LEFT, 1);
            break;
        case MANEUVER_LEFT_BACKWARD:
            BlueTooth::get()->logDebug("MANEUVER_LEFT_BACKWARD");
            Motors::get()->setSpeed(MOTOR_RIGHT, 0);
            Motors::get()->setSpeed(MOTOR_LEFT, -1);
            break;
        case MANEUVER_RIGHT_FORWARD:
            BlueTooth::get()->logDebug("MANEUVER_RIGHT_FORWARD");
            Motors::get()->setSpeed(MOTOR_LEFT, 0);
            Motors::get()->setSpeed(MOTOR_RIGHT, 1);
            break;
        case MANEUVER_RIGHT_BACKWARD:
            BlueTooth::get()->logDebug("MANEUVER_RIGHT_BACKWARD");
            Motors::get()->setSpeed(MOTOR_LEFT, 0);
            Motors::get()->setSpeed(MOTOR_RIGHT, 1);
            break;
        case MANEUVER_BOTH_FORWARD:
            BlueTooth::get()->logDebug("MANEUVER_BOTH_FORWARD");
            Motors::get()->setSpeed(1);
            break;
        case MANEUVER_BOTH_BACKWARD:
            BlueTooth::get()->logDebug("MANEUVER_BOTH_BACKWARD");
            Motors::get()->setSpeed(-1);
            break;
        case MANEUVER_ROTATE_LEFT:
            BlueTooth::get()->logDebug("MANEUVER_ROTATE_LEFT");
            Motors::get()->rotate(-1);
            break;
        case MANEUVER_ROTATE_RIGHT:
            BlueTooth::get()->logDebug("MANEUVER_ROTATE_RIGHT");
            Motors::get()->rotate(1);
            break;
    }
}
