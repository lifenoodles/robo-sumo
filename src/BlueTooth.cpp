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
    isDebugging = false;
    isReporting = true;
    reportTimer = 0;
    reportIntervalTime = 50;
    lastMessage = "";
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
    while (Serial.available() > 0)
    {
        // read the incoming byte:
        incomingByte = Serial.read();
        Serial.print("RECEIVED: ");
        Serial.println(incomingByte);
        if (incomingByte == MSG_REMOTE_CONTROL_TOGGLE)
        {
            Memory::get()->isRemoteControlled =
                !(Memory::get()->isRemoteControlled);
        }
    }
}

void BlueTooth::logDebug(String string)
{
    if (string != lastMessage && isDebugging)
    {
        Serial.print("D:");
        Serial.println(string);
    }
    lastMessage = string;
}

void BlueTooth::print(String string)
{
    Serial.print(string);
}

void BlueTooth::println(String string)
{
    Serial.println(string);
}

void BlueTooth::report(long delta)
{
    reportTimer += delta;
    if (reportTimer >
        reportIntervalTime)
    {
        reportTimer -= reportIntervalTime;
        Memory* memory = Memory::get();
        /*Serial.write((char) ECHO_FRONT);*/
        Serial.print("ECHO_FRONT:");
        Serial.println(
            Sensors::get()->echo->getValue(ECHO_FRONT));
        Serial.print("ECHO_BACK:");
        Serial.println(
            Sensors::get()->echo->getValue(ECHO_BACK));
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

void BlueTooth::setDebugging(bool isDebugging)
{
    this->isDebugging = isDebugging;
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

void BlueTooth::setReportingInterval(int interval)
{
    reportIntervalTime = interval;
}
