#include "SensorsIR.h"
#include "Pins.h"
#include "Memory.h"

unsigned char SensorsIR::irPins[4];
unsigned int SensorsIR::irValues[4];

SensorsIR::SensorsIR()
{
    int sensorCount = 4;
    Pins* pins = Memory::get()->pins;
    irPins[IR_FRONT_LEFT] = pins->IR_FRONT_LEFT;
    irPins[IR_FRONT_RIGHT] = pins->IR_FRONT_RIGHT;
    irPins[IR_BACK_LEFT] = pins->IR_BACK_LEFT;
    irPins[IR_BACK_RIGHT] = pins->IR_BACK_RIGHT;

    sensors = new QTRSensorsRC(irPins, sensorCount,
        5000, QTR_NO_EMITTER_PIN);
}

void SensorsIR::update(int milliseconds)
{
    sensors->read(irValues, QTR_EMITTERS_ON);
}

int SensorsIR::getValue(IDSensorsIR sensorID)
{
    return irValues[sensorID];
}
