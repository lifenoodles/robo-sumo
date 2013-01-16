#include "SensorsIR.h"
#include "Memory.h"
#include <stdlib.h>

SensorsIR::SensorsIR()
{
    int sensorCount = 4;
    Pins* pins = Memory::get()->pins;
    irPins = (unsigned char*) malloc(sizeof(unsigned char));// new unsigned char[sensorCount];
    irValues = (unsigned int*) malloc(sizeof(unsigned int));
    for(int i = 0; i < sensorCount; ++i)
    {
        irValues = 0;
    }
    irPins[0] = pins->IR_FRONT_LEFT;
    irPins[0] = pins->IR_FRONT_RIGHT;
    irPins[0] = pins->IR_BACK_LEFT;
    irPins[0] = pins->IR_BACK_RIGHT;

    sensors = new QTRSensorsRC(irPins, sensorCount,
        2500, QTR_NO_EMITTER_PIN);
    //calibrate sensors, should take ~ 1second
    for (int i = 0; i < 10; ++i)
    {
        sensors->calibrate();
    }
}

void SensorsIR::update(int milliseconds)
{
    sensors->readCalibrated(irValues, QTR_EMITTERS_OFF);
}

int SensorsIR::getSensorValue(IDSensorsIR sensorID)
{
    return irValues[sensorID];
}

SensorsIR::~SensorsIR()
{
    free(irPins);
    free(irValues);
}
