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
}

bool flag0 = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;

void loop()
{
    int timePassed = millis();
    /*Serial.println(Sensors::get()->ir->getSensorValue(IR_FRONT_RIGHT));*/
    //this will handle all sensor updates
    Sensors::get()->update(timePassed);
    if(timePassed > 5000 && !flag0)
    {
        flag0 = true;
        Motors::get()->setSpeed(1);
    }
    if(timePassed > 10000 && !flag1)
    {
        flag1 = true;
        Motors::get()->stop();
        Motors::get()->setSpeed(MOTOR_RIGHT, 1);
    }
    if(timePassed > 15000 && !flag2)
    {
        flag2 = true;
        Motors::get()->setSpeed(MOTOR_LEFT, 1);
    }
    if(timePassed > 20000 && !flag3)
    {
        flag3 = true;
        Motors::get()->rotate(1);
    }
    if(timePassed > 25000 && !flag4)
    {
        flag4 = true;
        Motors::get()->rotate(-1);
    }
    if(timePassed > 30000 && !flag5)
    {
        flag5 = true;
        Motors::get()->stop();
    }
}
