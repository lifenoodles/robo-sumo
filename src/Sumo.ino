#include "Sensors.h"
#include "Memory.h"
#include "Motors.h"
#include "Consts.h"
#include "BlueTooth.h"
#include "Behaviour.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    Serial.begin(9600);
    Serial.print("ID: ");
    Serial.println(id);
    //initialise memory based on robot id,
    //this needs to be done first!
    Memory::get()->init(id);
    BlueTooth::get()->setEnabled(true);
    BlueTooth::get()->setReporting(false);
    Serial.println(sizeof(long int));
    delay(1000);
}

long timer = 0;

bool flag1 = false;
bool flag2 = false;
bool flag3 = false;

void loop()
{
    long timePassed = millis();
    timer += timePassed;
    Sensors::get()->update(timePassed);
    Behaviour::get()->update(timePassed);
    BlueTooth::get()->report(timePassed);
    Serial.println(timePassed);
    if(timePassed > 5000 && !flag1)
    {
        flag1 = true;
        Motors::get()->setSpeed(1);
    }
    if(timePassed > 10000 && !flag2)
    {
        flag2 = true;
        Motors::get()->rotate(1);
    }
    if(timePassed > 15000 && !flag3)
    {
        flag3 = true;
        Motors::get()->rotate(-1);
    }
}
