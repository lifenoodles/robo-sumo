#include "SensorsEcho.h"
#include "NewPing.h"
#include "Memory.h"

SensorsEcho::SensorsEcho()
{
    timeSincePinged = 0;
    Pins* pins = Memory::get()->pins;
    sonarFront = new NewPing(pins->ECHO_FRONT_TRIGGER,
        pins->ECHO_FRONT_ECHO, 200);
    sonarBack = new NewPing(pins->ECHO_BACK_TRIGGER,
        pins->ECHO_BACK_ECHO, 200);
}

void SensorsEcho::update(int milliseconds)
{
    if (milliseconds - timeSincePinged > 10)
    {
        sonarDistance[ECHO_FRONT] = sonarFront->ping() / US_ROUNDTRIP_CM;
        sonarDistance[ECHO_BACK] = sonarBack->ping() / US_ROUNDTRIP_CM;
        timeSincePinged = milliseconds;
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
