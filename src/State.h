#ifndef GUARD_STATE
#define GUARD_STATE

class State
{
public:
    virtual void execute(long milliseconds) = 0;
};

class StateSearch : public State
{
public:
    void execute(long milliseconds);
private:
    bool handleIR(long milliseconds);
    bool handleEchoes(long milliseconds);
};

class StateChase : public State
{
public:
    void execute(long millisecond);
private:
    bool handleIR(long milliseconds);
    bool handleEchoes(long milliseconds);
};

#endif

