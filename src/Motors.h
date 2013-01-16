#ifndef GUARD_MOTORS
#define GUARD_MOTORS

class Motors
{
public:
    static Motors* get();
    void setLeftSpeed(float speed);
    void setRightSpeed(float speed);
    void move(float speed);
    void rotate(float speed);
    void stop();
private:
    static Motors* instance;
};

#endif
