#ifndef GUARD_BEHAVIOUR
#define GUARD_BEHAVIOUR

class Behaviour
{
public:
    void update(long milliseconds);
    static Behaviour* get();

private:
    Behaviour();
    static Behaviour* instance;
};

#endif
