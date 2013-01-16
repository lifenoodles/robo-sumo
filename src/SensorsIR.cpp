#include "SensorsIR.h"
#include "Pins.h"
#include "Memory.h"
#include <stdlib.h>

SensorsIR::SensorsIR()
{
    int sensorCount = 4;
    Pins* pins = Memory::get()->pins;
    irPins = (unsigned char*) malloc(sizeof(unsigned char)
        * sensorCount);// new unsigned char[sensorCount];
    irValues = (unsigned int*) malloc(sizeof(unsigned int)
        * sensorCount);
    for(int i = 0; i < sensorCount; ++i)
    {
        irValues = 0;
    }
    irPins[IR_FRONT_LEFT] = pins->IR_FRONT_LEFT;
    irPins[IR_FRONT_RIGHT] = pins->IR_FRONT_RIGHT;
    irPins[IR_BACK_LEFT] = pins->IR_BACK_LEFT;
    irPins[IR_BACK_RIGHT] = pins->IR_BACK_RIGHT;

    sensors = new QTRSensorsRC(irPins, sensorCount,
        5000, QTR_NO_EMITTER_PIN);
    //calibrate sensors, should take ~ 1second
/*    for (int i = 0; i < 10; ++i)
    {
        sensors->calibrate();
    }*/
}

void SensorsIR::update(int milliseconds)
{
    sensors->read(irValues, QTR_EMITTERS_ON);
}

int SensorsIR::getValue(IDSensorsIR sensorID)
{
    return irValues[sensorID];
}

SensorsIR::~SensorsIR()
{
    free(irPins);
    free(irValues);
}
