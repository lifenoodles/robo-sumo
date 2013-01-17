#ifndef GUARD_MOTORS
#define GUARD_MOTORS

#include "Consts.h"
#include <Arduino.h>

enum Motor
{
    MOTOR_LEFT, MOTOR_RIGHT
};

class Motors
{
public:
    static Motors* get();
    void setSpeed(Motor motor, float speed);
    void setSpeed(float speed);
    void rotate(float speed);
    void stop(Motor motor);
    void stop();
private:
    static Motors* instance;
    static int DIRECTION_FORWARD[2];
    static int DIRECTION_BACK[2];
};

#endif
