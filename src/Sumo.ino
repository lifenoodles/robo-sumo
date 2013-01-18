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
    BlueTooth::get()->setDebugging(true);
    BlueTooth::get()->setReporting(false);
    delay(2000);
    Serial.println("Ready");
}

long timer = 0;

void loop()
{
    long timePassed = millis();
    timer += timePassed;
    //BlueTooth::get()->read();
    Sensors::get()->update(timePassed);
    Behaviour::get()->update(timePassed);
    BlueTooth::get()->report(timePassed);
}
