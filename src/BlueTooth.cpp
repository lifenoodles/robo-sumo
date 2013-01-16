#include "BlueTooth.h"
#include "Memory.h"
#include "Sensors.h"
#include <Arduino.h>

BlueTooth* BlueTooth::instance = 0;

BlueTooth::BlueTooth()
{
    isReporting = true;
}

BlueTooth* BlueTooth::get()
{
    if (instance == 0)
    {
        instance = new BlueTooth();
    }
    return instance;
}

String BlueTooh::read()
{
    int incomingByte;
    if (Serial.available() > 0)
    {
        // read the incoming byte:
        incomingByte = Serial.read();
    }
}

void BlueTooth::print(String string)
{
    Serial.print(string);
}

void BlueTooth::println(String string)
{
    Serial.println(string);
}

void BlueTooth::report()
{
    if (isReporting)
    {
        Memory* memory = Memory::get();
        /*Serial.write((char) ECHO_FRONT);*/
        Serial.print("ECHO_FRONT:")
        Serial.println(
            Sensors::get()->echo->getSensorValue(ECHO_FRONT));
        Serial.print("ECHO_BACK:")
        Serial.println(
            Sensors::get()->echo->getSensorValue(ECHO_BACK));
    }
}
