#ifndef GUARD_BEHAVIOUR
#define GUARD_BEHAVIOUR

#include "SensorReader.h"

class Behaviour
{
public:
    void update(long milliseconds);
    static Behaviour* get();

private:
    Behaviour();
    SensorReader* sensorReader;
    static Behaviour* instance;
};

#endif
