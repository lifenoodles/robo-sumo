#ifndef GUARD_MOTORS
#define GUARD_MOTORS

#include "Consts.h"
#include <Arduino.h>

class Motors
{
public:
    static Motors* get();
    void setSpeed(Motor motor, float speed);
    void move(float speed);
    void rotate(float speed);
    void stop();
private:
    static Motors* instance;
    static int DIRECTION_FORWARD[2];
    static int DIRECTION_BACK[2];
};

#endif
