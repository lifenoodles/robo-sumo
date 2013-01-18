#ifndef GUARD_SENSORS_ECHO
#define GUARD_SENSORS_ECHO

#include "NewPing.h"

enum EchoSensorId
{
    ECHO_FRONT = 0,
    ECHO_BACK = 1,
    ECHO_NUM_SENSORS = 2
};

class SensorsEcho
{
public:
    SensorsEcho();
    ~SensorsEcho();
    int getValue(int sensorID);
    void update(long milliseconds);
    bool isEchoFired;
private:
    long timeSincePinged;
    int pingTime;
    int sonarDistance[2];
    NewPing* sonarFront;
    NewPing* sonarBack;
};
#endif
