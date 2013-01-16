#include "Pins.h"
#include "Consts.h"

Pins::Pins(unsigned char id)
{
    switch (id)
    {
        case ID_TITAN:
            ECHO_FRONT_TRIGGER = 4;
            ECHO_FRONT_ECHO = 5;
            ECHO_BACK_TRIGGER = 8;
            ECHO_BACK_ECHO = 9;
            MOTOR_LEFT_A = 14;
            MOTOR_LEFT_B = 15;
            MOTOR_RIGHT_A = 16;
            MOTOR_RIGHT_B = 17;
            break;

        case ID_PHOBOS:
            ECHO_FRONT_TRIGGER = -1;
            ECHO_FRONT_ECHO = -1;
            ECHO_BACK_TRIGGER = -1;
            ECHO_BACK_ECHO = -1;
            MOTOR_LEFT_A = 10;
            MOTOR_LEFT_B = 11;
            MOTOR_RIGHT_A = 3;
            MOTOR_RIGHT_B = 5;
            break;
    }
}
