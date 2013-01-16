#include "SensorsEcho.h"
#include "Memory.h"
#include "Consts.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    Serial.begin(115200);

    //initialise memory based on robot id
    Memory::get()->init(id);
}

void loop()
{

}
