#include "SensorsEcho.h"
#include "Consts.h"
#include "NewPing.h"

SensorsEcho::SensorsEcho()
{
    timeSincePinged = 0;
    sonarFront = new NewPing(ECHO_FRONT_TRIGGER, ECHO_FRONT_ECHO, 200);
    sonarBack = new NewPing(ECHO_BACK_TRIGGER, ECHO_BACK_ECHO, 200);
}

void SensorsEcho::update()
{
    int time = millis();
    if (time - timeSincePinged > 10)
    {
        sonarDistance[ECHO_FRONT] = sonarFront->ping() / US_ROUNDTRIP_CM;
        sonarDistance[ECHO_BACK] = sonarBack->ping() / US_ROUNDTRIP_CM;
        timeSincePinged = time;
    }
}

int SensorsEcho::getSensorValue(int sensorID)
{
    return sonarDistance[sensorID];
}

SensorsEcho::~SensorsEcho()
{
    delete sonarFront;
    delete sonarBack;
}
