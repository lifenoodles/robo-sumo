#include "Sensors.h"
#include "Memory.h"
#include "Motors.h"
#include "Consts.h"
#include "BlueTooth.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    EEPROM.write(ADDRESS_ID, ID_PHOBOS);
    char id = EEPROM.read(ADDRESS_ID);
    Serial.begin(9600);
    Serial.print("ID: ");
    Serial.println(id);
    //initialise memory based on robot id,
    //this needs to be done first!
    Memory::get()->init(id);
    BlueTooth::get()->setEnabled(true);
    BlueTooth::get()->setReporting(true);
}

int timer = 0;

void loop()
{
    int timePassed = millis();
    timer += timePassed;
    if(timer > 50)
    {
        BlueTooth::get()->report();
        timer = 0;
    }
    Sensors::get()->update(timePassed);
   /* Serial.println(Sensors::get()->ir->getValue(IR_BACK_LEFT), DEC);
    Serial.print("\t\t");
    Serial.println(Sensors::get()->ir->getValue(IR_BACK_RIGHT), DEC);*/
    //int x = 5;
    //Serial.println(x);
    //Serial.println(5);
}
