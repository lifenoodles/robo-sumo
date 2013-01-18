#include "Sensors.h"
#include "Consts.h"

Sensors* Sensors::instance = 0;

Sensors::Sensors()
{
    echo = new SensorsEcho();
    ir = new SensorsIR();
}

void Sensors::update(long delta)
{
    echo->update(delta);
    ir->update(delta);
}

Sensors* Sensors::get()
{
    if (instance == 0)
    {
        instance = new Sensors();
    }
    return instance;
}
