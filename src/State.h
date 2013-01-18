#ifndef GUARD_STATE
#define GUARD_STATE

#include "Maneuver.h"

class State
{
public:
    virtual void execute(long delta) = 0;
    void setTimer(long newTime);
    Maneuver* currentManeuver;
    static Maneuver* maneuverScan;
    static Maneuver* maneuverBackup;
    static Maneuver* maneuverRotate;

protected:
    long timer;
};

class StateSearch : public State
{
public:
    StateSearch()
    {
        timer = 0;
        currentManeuver = 0;
        rotationDirection = 1;
    }
    void execute(long delta);
private:
    int rotationDirection;
    bool handleIR(long delta);
    bool handleEchoes(long delta);
};

class StateChase : public State
{
public:
    StateChase()
    {
        timer = 0;
        timeoutTimer = 0;
        currentManeuver = 0;
    }
    void execute(long millisecond);
private:
    long timeoutTimer;
    bool handleIR(long delta);
    bool handleEchoes(long delta);
};

#endif

