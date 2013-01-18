#include "SensorReader.h"
#include "RingBuffer.h"
#include "SensorsIR.h"
#include "Sensors.h"
#include "Memory.h"

RingBuffer<int, 1> SensorReader::ledReadings[4];
RingBuffer<int, 5> SensorReader::echoReadings[2];

SensorReader::SensorReader()
{
    pollingRate = 5;
    timeSinceLastPoll = 0;
}

void SensorReader::update(long milliseconds)
{
    Sensors* sensors = Sensors::get();
    for (int i = 0; i < IR_NUM_SENSORS; ++i)
    {
        ledReadings[i].add(sensors->ir->getValue(i));
    }
    processIrData(milliseconds);

    if (sensors->echo->isEchoFired)
    {
        sensors->echo->isEchoFired = false;
        for(int i = 0; i < ECHO_NUM_SENSORS; ++i)
        {
            echoReadings[i].add(sensors->echo->getValue(i));
        }
        processEchoData(milliseconds);
    }
}

void SensorReader::processIrData(long milliseconds)
{
    int thresholdLimit = 0;
    Offsets* offsets = Memory::get()->offsets;
    WorldState* worldState = Memory::get()->worldState;
    //if we get 3 or more sensors in a row
    for (int sensor = 0; sensor < IR_NUM_SENSORS; ++sensor)
    {
        int countBelowThreshold = 0;
        for (int i = 0, n = ledReadings[sensor].getNumberOfEntries(); i < n; ++i)
        {
            if (ledReadings[sensor][i] < Offsets::thresholds[sensor])
            {
                ++countBelowThreshold;
            }
        }
        if (countBelowThreshold > thresholdLimit)
        {
            worldState->irSensorsOn[sensor] = true;
        }
        else
        {
            worldState->irSensorsOn[sensor] = false;
        }
    }
}

void SensorReader::processEchoData(long milliseconds)
{
    Offsets* offsets = Memory::get()->offsets;
    WorldState* worldState = Memory::get()->worldState;
    //ECHO sensors
    if (echoReadings[ECHO_FRONT][0] > 0
        &&  echoReadings[ECHO_FRONT][0] < offsets->farDistanceThreshold)
    {
        worldState->isOpponentDetected = true;
        worldState->lastOpponentDistance =
            echoReadings[ECHO_FRONT][0];
        worldState->timeSinceOpponentDetected = milliseconds;
    }
}

void SensorReader::setPollingRate(int pollingRate)
{
    this->pollingRate = pollingRate;
}


