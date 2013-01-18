#include "Pins.h"
#include "Consts.h"
#include <Arduino.h>

Pins::Pins(unsigned char id)
{
    switch (id)
    {
        case ID_TITAN:
            IR_FRONT_LEFT = 7;
            IR_FRONT_RIGHT = 12;
            IR_BACK_LEFT = 11;
            IR_BACK_RIGHT = 10;
            ECHO_FRONT_TRIGGER = 4;
            ECHO_FRONT_ECHO = 5;
            ECHO_BACK_TRIGGER = 8;
            ECHO_BACK_ECHO = 9;
            MOTOR_LEFT_A = 14;
            MOTOR_LEFT_B = 15;
            MOTOR_RIGHT_A = 16;
            MOTOR_RIGHT_B = 17;
            BLUE_TOOTH_ENABLE = 2;
            SERVO_LEFT = -1;
            SERVO_RIGHT = -1;
            pinMode(MOTOR_LEFT_A, OUTPUT);
            pinMode(MOTOR_LEFT_B, OUTPUT);
            pinMode(MOTOR_RIGHT_A, OUTPUT);
            pinMode(MOTOR_RIGHT_B, OUTPUT);
            pinMode(BLUE_TOOTH_ENABLE, OUTPUT);
            digitalWrite(MOTOR_LEFT_A, LOW);
            digitalWrite(MOTOR_LEFT_B, LOW);
            digitalWrite(MOTOR_RIGHT_A, LOW);
            digitalWrite(MOTOR_RIGHT_B, LOW);
            digitalWrite(BLUE_TOOTH_ENABLE, HIGH);
            break;

        case ID_PHOBOS:
            IR_FRONT_LEFT = 2;
            IR_FRONT_RIGHT = 12;
            IR_BACK_LEFT = 21;
            IR_BACK_RIGHT = 13;
            ECHO_FRONT_TRIGGER = 6;
            ECHO_FRONT_ECHO = 7;
            ECHO_BACK_TRIGGER = 8;
            ECHO_BACK_ECHO = 9;
            MOTOR_LEFT_A = 5;
            MOTOR_LEFT_B = 15;
            MOTOR_RIGHT_A = 12;
            MOTOR_RIGHT_B = 14;
            BLUE_TOOTH_ENABLE = -1;
            SERVO_LEFT = 3;
            SERVO_RIGHT = 11;
            pinMode(MOTOR_LEFT_A, OUTPUT);
            pinMode(MOTOR_LEFT_B, OUTPUT);
            pinMode(MOTOR_RIGHT_A, OUTPUT);
            pinMode(MOTOR_RIGHT_B, OUTPUT);
            digitalWrite(MOTOR_LEFT_A, LOW);
            digitalWrite(MOTOR_LEFT_B, LOW);
            digitalWrite(MOTOR_RIGHT_A, LOW);
            digitalWrite(MOTOR_RIGHT_B, LOW);
            break;
    }
}
