#ifndef GUARD_SENSORS_IR
#define GUARD_SENSORS_IR

#include "QTRSensors.h"

enum IDSensorsIR
{
    IR_FRONT_LEFT = 0,
    IR_FRONT_RIGHT = 1,
    IR_BACK_LEFT = 2,
    IR_BACK_RIGHT = 3,
    IR_NUM_SENSORS = 4
};

class SensorsIR
{
public:
    SensorsIR();
    int getValue(int sensorID);
    void update(long delta);
private:
    static unsigned char irPins[4];
    static unsigned int irValues[4];
    QTRSensorsRC* sensors;
};

#endif
