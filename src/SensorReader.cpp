#include "SensorReader.h"
#include "RingBuffer.h"
#include "SensorsIR.h"
#include "Sensors.h"
#include "Memory.h"
#include "stdlib.h"

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

int cmp(const void* num1, const void* num2)
{
    int a = *((int*)num1);
    int b = *((int*)num2);
    if (a > b) return  1;
    if (b < a) return -1;
    return 0;
}

void SensorReader::processEchoData(long milliseconds)
{
    Offsets* offsets = Memory::get()->offsets;
    WorldState* worldState = Memory::get()->worldState;

    int medianDistance = 0;
    int count = echoReadings[ECHO_FRONT].getMaxEntries();
    for (int i = 0; i < count; ++i)
    {
        frontSortBuffer[i] = echoReadings[ECHO_FRONT][i];
        backSortBuffer[i] = echoReadings[ECHO_BACK][i];
    }
    qsort(frontSortBuffer, count, sizeof(int), cmp);
    qsort(backSortBuffer, count, sizeof(int), cmp);

    medianDistance = frontSortBuffer[count / 2];

    if (medianDistance > 0 &&
        medianDistance < offsets->farDistanceThreshold)
    {
        worldState->isOpponentDetected = true;
        worldState->lastOpponentDistance = medianDistance;
        worldState->timeOpponentDetected = milliseconds;
    }
}

void SensorReader::setPollingRate(int pollingRate)
{
    this->pollingRate = pollingRate;
}


