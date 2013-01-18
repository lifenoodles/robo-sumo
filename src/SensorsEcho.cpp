#include "SensorsEcho.h"
#include "NewPing.h"
#include "Memory.h"

SensorsEcho::SensorsEcho()
{
    isEchoFired = false;
    pingTimer = 0;
    pingTime = 33;
    Pins* pins = Memory::get()->pins;
    sonarFront = new NewPing(pins->ECHO_FRONT_TRIGGER,
        pins->ECHO_FRONT_ECHO, 40);
    sonarBack = new NewPing(pins->ECHO_BACK_TRIGGER,
        pins->ECHO_BACK_ECHO, 40);
    sonarDistance[ECHO_FRONT] = 77;
    sonarDistance[ECHO_FRONT] = 77;
}

void SensorsEcho::update(long delta)
{
    pingTimer += delta;
    if (pingTimer >= pingTime)
    {
        sonarDistance[ECHO_FRONT] = sonarFront->ping()
            / US_ROUNDTRIP_CM;
        sonarDistance[ECHO_BACK] = sonarBack->ping()
            / US_ROUNDTRIP_CM;
        isEchoFired = true;
        pingTimer -= pingTime;
    }
}

int SensorsEcho::getValue(int sensorID)
{
    return sonarDistance[sensorID];
}

SensorsEcho::~SensorsEcho()
{
    delete sonarFront;
    delete sonarBack;
}
