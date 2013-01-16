#include "Motors.h"
#include "Memory.h"

Motors* Motors::instance = 0;

Motors* Motors::get()
{
    if (instance == 0)
    {
        instance = new Motors();
    }
    return instance;
}

void Motors::setLeftSpeed(float speed)
{

}

void Motors::setRightSpeed(float speed)
{

}

void Motors::move(float speed)
{
    Pins* pins = Memory::get()->pins;
    digitalWrite(pins->MOTOR_LEFT_A, HIGH);
}

void Motors::rotate(float speed)
{

}

void Motors::stop()
{

}
