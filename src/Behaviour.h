#ifndef GUARD_BEHAVIOUR
#define GUARD_BEHAVIOUR

#include "SensorReader.h"
#include "State.h"
#include "Maneuver.h"

class Behaviour
{
public:
    void update(long delta, long totalTime);
    void setState(State& state);
    StateSearch stateSearch;
    StateChase stateChase;
    static Behaviour* get();
private:
    Behaviour();
    State* currentState;
    SensorReader* sensorReader;
    // Maneuver manuevers[5];
    static Behaviour* instance;
};

#endif
