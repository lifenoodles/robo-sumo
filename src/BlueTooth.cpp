#include "BlueTooth.h"
#include "Memory.h"
#include "Sensors.h"
#include "SensorsEcho.h"
#include "SensorsIR.h"
#include "Pins.h"
#include "Consts.h"
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

String BlueTooth::read()
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
        Serial.print("ECHO_FRONT:");
        Serial.println(
            Sensors::get()->echo->getSensorValue(ECHO_FRONT));
        Serial.print("ECHO_BACK:");
        Serial.println(
            Sensors::get()->echo->getSensorValue(ECHO_BACK));
        Serial.print("IR_BACKLEFT:");
        Serial.println(
            Sensors::get()->ir->getValue(IR_BACK_LEFT));
        Serial.print("IR_BACKRIGHT:");
        Serial.println(
            Sensors::get()->ir->getValue(IR_BACK_RIGHT));
        Serial.print("IR_FRONTLEFT:");
        Serial.println(
            Sensors::get()->ir->getValue(IR_FRONT_LEFT));
        Serial.print("IR_FRONTRIGHT:");
        Serial.println(
            Sensors::get()->ir->getValue(IR_FRONT_RIGHT));
    }
}

void BlueTooth::setReporting(bool isReporting)
{
    this->isReporting = isReporting;
}

void BlueTooth::setEnabled(bool isEnabled)
{
    if(Memory::get()->getID() == ID_TITAN)
    {
        if (isEnabled)
        {
            digitalWrite(Memory::get()->pins->BLUE_TOOTH_ENABLE, HIGH);
        }
        else
        {
            setReporting(false);
            digitalWrite(Memory::get()->pins->BLUE_TOOTH_ENABLE, LOW);
        }
    }
}
