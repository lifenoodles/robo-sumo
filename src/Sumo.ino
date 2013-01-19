#include "Sensors.h"
#include "Memory.h"
#include "Motors.h"
#include "Consts.h"
#include "BlueTooth.h"
#include "Behaviour.h"
#include <EEPROM.h>
#include <Servo.h>

SensorsEcho sensorsEcho;

void setup()
{
    // EEPROM.write(ADDRESS_ID, ID_PHOBOS);
    char id = EEPROM.read(ADDRESS_ID);
    Serial.begin(9600);
    Serial.print("ID: ");
    Serial.println(id);
    //initialise memory based on robot id,
    //this needs to be done first!
    Memory::get()->init(id);
    BlueTooth::get()->setDebugging(true);
    BlueTooth::get()->setReporting(true);
    randomSeed(analogRead(0));

    if (id == ID_PHOBOS)
    {
        Servo servoLeft, servoRight;
        servoLeft.attach(Memory::get()->pins->SERVO_LEFT);
        servoRight.attach(Memory::get()->pins->SERVO_RIGHT);

        int servoLeftMin = 134;
        int servoLeftMax = 14;
        int servoRightMin = 5;
        int servoRightMax = 125;

        servoLeft.write(servoLeftMin);
        servoRight.write(servoRightMin);
        delay(1000);
        servoLeft.write(servoLeftMax);
        servoRight.write(servoRightMax);
    }
    else if (id == ID_TITAN)
    {
        delay(3000);
    }
    else
    {
        Serial.println("Unrecognised ID, Abort.");
    }
    Serial.println("Ready");
}

long lastTime = 0;
long nowTime = 0;

void loop()
{
    nowTime = millis();
    long delta = nowTime - lastTime;
    lastTime = nowTime;
    //BlueTooth::get()->read();
    Sensors::get()->update(delta);
    Behaviour::get()->update(delta, nowTime);
    BlueTooth::get()->report(delta);
}
