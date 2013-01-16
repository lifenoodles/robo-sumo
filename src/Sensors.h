#ifndef GUARD_SENSORS
#define GUARD_SENSORS

#include "SensorsEcho.h"

class Sensors
{
public:
    Sensors();
    void update(int milliseconds);
    static Sensors* get();
    SensorsEcho* echo;
private:
    static Sensors* instance;
};

#endif
