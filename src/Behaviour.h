#ifndef GUARD_BEHAVIOUR
#define GUARD_BEHAVIOUR

#include "SensorReader.h"
#include "State.h"

class Behaviour
{
public:
    void update(long delta);
    void setState(State& state);
    StateSearch stateSearch;
    StateChase stateChase;
    static Behaviour* get();
private:
    Behaviour();
    State* currentState;
    SensorReader* sensorReader;
    static Behaviour* instance;
};

#endif
