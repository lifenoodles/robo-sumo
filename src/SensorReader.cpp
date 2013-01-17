#include "SensorReader.h"
#include "RingBuffer.h"
#include "SensorsIR.h"
#include "Sensors.h"
#include "Memory.h"

RingBuffer<int, 1> SensorReader::ledReadings[4];
RingBuffer<int, 10> SensorReader::echoReadings[2];

SensorReader::SensorReader()
{
    pollingRate = 5;
    timeSinceLastPoll = 0;
}

void SensorReader::update(long milliseconds)
{
    if (milliseconds - timeSinceLastPoll > pollingRate)
    {
        timeSinceLastPoll = milliseconds;
        Sensors* sensors = Sensors::get();
        for (int i = 0; i < IR_NUM_SENSORS; ++i)
        {
            ledReadings[i].add(sensors->ir->getValue(i));
        }
        for(int i = 0; i < ECHO_NUM_SENSORS; ++i)
        {
            echoReadings[i].add(sensors->echo->getValue(i));
        }
        processSensorData();
    }
}

void SensorReader::processSensorData()
{
    int thresholdLimit = 0;
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

void SensorReader::setPollingRate(int pollingRate)
{
    this->pollingRate = pollingRate;
}


