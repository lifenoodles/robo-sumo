#include "Sensors.h"
#include "Memory.h"
#include "Motors.h"
#include "Consts.h"
#include "BlueTooth.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    //initialise memory based on robot id,
    //this needs to be done first!
    Serial.begin(9600);
    Serial.print("STARTING ID = ");
    Serial.println(id);
    Memory::get()->init(id);
    BlueTooth::get()->setReporting(false);
}

int timer = 0;

void loop()
{
    int timePassed = millis();
    timer += timePassed;
/*    if(timer > 20)
    {
        BlueTooth::get()->report();
        timer = 0;
    }*/
    Sensors::get()->update(timePassed);
    /*Serial.println("Cockballs");*/
    Serial.println(IR_BACK_LEFT);
    //Serial.println(Sensors::get()->ir->getValue(IR_BACK_LEFT));
    delay(200);
}
