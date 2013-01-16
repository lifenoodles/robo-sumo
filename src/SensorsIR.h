#ifndef GUARD_SENSORS_IR
#define GUARD_SENSORS_IR

#include "QTRSensors.h"

enum IDSensorsIR
{
    IR_FRONT_LEFT = 0,
    IR_FRONT_RIGHT = 1,
    IR_BACK_LEFT = 2,
    IR_BACK_RIGHT = 3
};

class SensorsIR
{
public:
    SensorsIR();
    ~SensorsIR();
    int getValue(IDSensorsIR sensorID);
    void update(int milliseconds);
private:
    unsigned char* irPins;
    unsigned int* irValues;
    int timeSincePinged;
    QTRSensorsRC* sensors;
};

#endif
