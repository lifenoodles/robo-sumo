#ifndef GUARD_SENSORS_ECHO
#define GUARD_SENSORS_ECHO

#include "NewPing.h"

class SensorsEcho
{
public:
    SensorsEcho();
    ~SensorsEcho();
    int getSensorValue(int sensorID);
    void update();
private:
    int timeSincePinged;
    float sonarDistance[2];
    NewPing* sonarFront;
    NewPing* sonarBack;
};

#endif
