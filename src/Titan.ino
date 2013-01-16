#include "Sensors.h"
#include "Memory.h"
#include "Motors.h"
#include "Consts.h"
#include <EEPROM.h>

SensorsEcho sensorsEcho;

void setup()
{
    char id = EEPROM.read(ADDRESS_ID);
    //initialise memory based on robot id,
    //this needs to be done first!
    Serial.begin(115200);
    Serial.print("STARTING ID = ");
    Serial.println(id);
    Memory::get()->init(id);
    Motors::get()->setSpeed(MOTOR_LEFT, 0.1);
}

bool flag1 = false;
bool flag2 = false;

void loop()
{
    int timePassed = millis();
    //this will handle all sensor updates
    Sensors::get()->update(timePassed);
    if(timePassed > 5000 && !flag1)
    {
        flag1 = true;
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    if(timePassed > 10000 && !flag2)
    {
        flag2 = true;
        Motors::get()->setSpeed(MOTOR_LEFT, 0);
    }
}
