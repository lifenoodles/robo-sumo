#include "Motors.h"
#include "Memory.h"
#include "Consts.h"
#include <Arduino.h>

Motors* Motors::instance = 0;
int Motors::DIRECTION_FORWARD[2] = {HIGH, LOW};
int Motors::DIRECTION_BACK[2] = {LOW, HIGH};

Motors* Motors::get()
{
    if (instance == 0)
    {
        instance = new Motors();
    }
    return instance;
}

void Motors::setSpeed(Motor motor, float speed)
{
    Pins* pins = Memory::get()->pins;
    int* direction;
    if (speed < 0)
        direction = DIRECTION_BACK;
    else if (speed > 0)
        direction = DIRECTION_FORWARD;
    else
    {
        stop();
        return;
    }
    int pin_a, pin_b;
    if (motor == MOTOR_LEFT)
    {
        pin_a = pins->MOTOR_LEFT_A;
        pin_b = pins->MOTOR_LEFT_B;
    }
    else if (motor == MOTOR_RIGHT)
    {
        pin_a = pins->MOTOR_RIGHT_A;
        pin_b = pins->MOTOR_RIGHT_B;
    }

    digitalWrite(pin_a, direction[0]);
    digitalWrite(pin_b, direction[1]);
}

void Motors::setSpeed(float speed)
{
    Pins* pins = Memory::get()->pins;
    int* direction;
    if (speed < 0)
        direction = DIRECTION_BACK;
    else if (speed > 0)
        direction = DIRECTION_FORWARD;
    else
    {
        stop();
        return;
    }

    digitalWrite(pins->MOTOR_LEFT_A, direction[0]);
    digitalWrite(pins->MOTOR_LEFT_B, direction[1]);
    digitalWrite(pins->MOTOR_RIGHT_A, direction[0]);
    digitalWrite(pins->MOTOR_RIGHT_B, direction[1]);
}

void Motors::rotate(float speed)
{
    Pins* pins = Memory::get()->pins;
    if (speed < 0)
    {
        digitalWrite(pins->MOTOR_LEFT_A, DIRECTION_BACK[0]);
        digitalWrite(pins->MOTOR_LEFT_B, DIRECTION_BACK[1]);
        digitalWrite(pins->MOTOR_RIGHT_A, DIRECTION_FORWARD[0]);
        digitalWrite(pins->MOTOR_RIGHT_B, DIRECTION_FORWARD[1]);
    }
    else if (speed > 0)
    {
        digitalWrite(pins->MOTOR_LEFT_A, DIRECTION_FORWARD[0]);
        digitalWrite(pins->MOTOR_LEFT_B, DIRECTION_FORWARD[1]);
        digitalWrite(pins->MOTOR_RIGHT_A, DIRECTION_BACK[0]);
        digitalWrite(pins->MOTOR_RIGHT_B, DIRECTION_BACK[1]);
    }
    else
    {
        stop();
    }
}

void Motors::stop()
{
    Pins* pins = Memory::get()->pins;
    digitalWrite(pins->MOTOR_LEFT_A, LOW);
    digitalWrite(pins->MOTOR_LEFT_B, LOW);
    digitalWrite(pins->MOTOR_RIGHT_A, LOW);
    digitalWrite(pins->MOTOR_RIGHT_B, LOW);
}

void Motors::stop(Motor motor)
{
    Pins* pins = Memory::get()->pins;
    int pin_a, pin_b;
    if (motor == MOTOR_LEFT)
    {
        pin_a = pins->MOTOR_LEFT_A;
        pin_b = pins->MOTOR_LEFT_B;
    }
    else if (motor == MOTOR_RIGHT)
    {
        pin_a = pins->MOTOR_RIGHT_A;
        pin_b = pins->MOTOR_RIGHT_B;
    }

    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, LOW);
}
