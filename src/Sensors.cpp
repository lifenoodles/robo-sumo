#include "Sensors.h"
#include "Consts.h"

Sensors* Sensors::instance = 0;

Sensors::Sensors()
{
    echo = new SensorsEcho();
}

Sensors* Sensors::get()
{
    if (instance == 0)
    {
        instance = new Sensors();
    }
    return instance;
}
