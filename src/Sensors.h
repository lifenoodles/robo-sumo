#ifndef GUARD_SENSORS
#define GUARD_SENSORS

#include "SensorsEcho.h"
#include "SensorsIR.h"

class Sensors
{
public:
    Sensors();
    void update(int milliseconds);
    static Sensors* get();
    SensorsEcho* echo;
    SensorsIR* ir;

private:
    static Sensors* instance;
};

#endif
