#include "SensorsEcho.h"
#include "Consts.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    Serial.begin(115200);
    Serial.print(id);
}

void loop()
{

}
