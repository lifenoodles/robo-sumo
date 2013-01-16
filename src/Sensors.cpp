#include "Sensors.h"
#include "Consts.h"

Sensors* Sensors::instance = 0;

Sensors::Sensors()
{
    echo = new SensorsEcho();
    ir = new SensorsIR();
}

void Sensors::update(int milliseconds)
{
    echo->update(milliseconds);
    ir->update(milliseconds);
}

Sensors* Sensors::get()
{
    if (instance == 0)
    {
        instance = new Sensors();
    }
    return instance;
}
