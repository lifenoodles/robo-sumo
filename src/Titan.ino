#include "Sensors.h"
#include "Memory.h"
#include "Consts.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    //initialise memory based on robot id,
    //this needs to be done first!
    Memory::get()->init(id);
    Serial.begin(115200);
}

void loop()
{
    int timePassed = millis();
    //this will handle all sensor updates
    Sensors::get()->update(timePassed);
}
