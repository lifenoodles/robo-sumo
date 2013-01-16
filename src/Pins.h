#ifndef GUARD_PINS
#define GUARD_PINS

class Pins
{
public:
    Pins(unsigned char id);

    unsigned int ECHO_FRONT_TRIGGER;
    unsigned int ECHO_FRONT_ECHO;
    unsigned int ECHO_BACK_TRIGGER;
    unsigned int ECHO_BACK_ECHO;
    unsigned int MOTOR_LEFT_A;
    unsigned int MOTOR_LEFT_B;
    unsigned int MOTOR_RIGHT_A;
    unsigned int MOTOR_RIGHT_B;
};

#endif
