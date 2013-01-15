typedef enum
{
    MOTOR_LEFT, MOTOR_RIGHT
}
motor_t;

typedef enum
{
    IR_FRONT_LEFT, IR_FRONT_RIGHT, IR_BOTTOM_LEFT, IR_BOTTOM_RIGHT
}
ir_t;

typedef enum
{
    ECHO_FRONT = 0, ECHO_BACK = 1
}
echo_t;

typedef enum
{
    ECHO_FRONT_TRIGGER = 4,
    ECHO_FRONT_ECHO = 5,
    ECHO_BACK_TRIGGER = 8,
    ECHO_BACK_ECHO = 9
}
pin_t;

