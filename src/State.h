#ifndef GUARD_STATE
#define GUARD_STATE

class State
{
public:
    virtual void execute(long delta) = 0;
};

class StateSearch : public State
{
public:
    void execute(long delta);
private:
    bool handleIR(long delta);
    bool handleEchoes(long delta);
};

class StateChase : public State
{
public:
    StateChase():timeoutTimer(0){}
    void execute(long millisecond);
private:
    long timeoutTimer;
    bool handleIR(long delta);
    bool handleEchoes(long delta);
};

#endif

