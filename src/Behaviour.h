#ifndef GUARD_BEHAVIOUR
#define GUARD_BEHAVIOUR

#include "SensorReader.h"
#include "State.h"

class Behaviour
{
public:
    void update(long milliseconds);
    static Behaviour* get();
private:
    Behaviour();
    StateSearch stateSearch;
    StateChase stateChase;
    State* currentState;
    SensorReader* sensorReader;
    static Behaviour* instance;
};

#endif
