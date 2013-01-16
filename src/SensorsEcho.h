#ifndef GUARD_SENSORS_ECHO
#define GUARD_SENSORS_ECHO

#include "NewPing.h"

enum EchoSensorId
{
    ECHO_FRONT = 0, ECHO_BACK = 1
};

class SensorsEcho
{
public:
    SensorsEcho();
    ~SensorsEcho();
    int getSensorValue(int sensorID);
    void update(int milliseconds);


private:
    int timeSincePinged;
    float sonarDistance[2];
    NewPing* sonarFront;
    NewPing* sonarBack;
};
#endif
