#include "Maneuver.h"
#include "Motors.h"

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
    while (!isDone() && moveTimer > moves[moveIndex])
    {
        moveTimer -= times[moveIndex];
        ++moveIndex;
    }
    if (!isDone())
        moveMotor(moveIndex);
}

bool Maneuver::isDone()
{
    return moveIndex >= moveCount;
}

void Maneuver::moveMotor(int moveId)
{
    switch (moveId)
    {
        case MANEUVER_LEFT_FORWARD:
            Motors::get()->setSpeed(MOTOR_LEFT, 1);
            break;
        case MANEUVER_LEFT_BACKWARD:
            Motors::get()->setSpeed(MOTOR_LEFT, -1);
            break;
        case MANEUVER_RIGHT_FORWARD:
            Motors::get()->setSpeed(MOTOR_RIGHT, 1);
            break;
        case MANEUVER_RIGHT_BACKWARD:
            Motors::get()->setSpeed(MOTOR_RIGHT, 1);
            break;
        case MANEUVER_BOTH_FORWARD:
            Motors::get()->setSpeed(1);
            break;
        case MANEUVER_BOTH_BACKWARD:
            Motors::get()->setSpeed(-1);
            break;
    }
}
