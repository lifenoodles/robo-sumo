#include "sensors_echo.h"
#include "titan_consts.h"

SensorsEcho sensorsEcho;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    sensorsEcho.update();
    Serial.print("Ping Front: ");
    Serial.print(sensorsEcho.getSensorValue(ECHO_FRONT));
    Serial.print("cm    \t");
    Serial.print("Ping Back: ");
    Serial.print(sensorsEcho.getSensorValue(ECHO_BACK));
    Serial.println("cm");
}
