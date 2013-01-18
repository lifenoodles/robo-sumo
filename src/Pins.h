#ifndef GUARD_PINS
#define GUARD_PINS

class Pins
{
public:
    Pins(unsigned char id);

    unsigned int IR_FRONT_LEFT;
    unsigned int IR_FRONT_RIGHT;
    unsigned int IR_BACK_LEFT;
    unsigned int IR_BACK_RIGHT;
    unsigned int ECHO_FRONT_TRIGGER;
    unsigned int ECHO_FRONT_ECHO;
    unsigned int ECHO_BACK_TRIGGER;
    unsigned int ECHO_BACK_ECHO;
    unsigned int MOTOR_LEFT_A;
    unsigned int MOTOR_LEFT_B;
    unsigned int MOTOR_RIGHT_A;
    unsigned int MOTOR_RIGHT_B;
    unsigned int BLUE_TOOTH_ENABLE;
    unsigned int SERVO_LEFT;
    unsigned int SERVO_RIGHT;
};

#endif
