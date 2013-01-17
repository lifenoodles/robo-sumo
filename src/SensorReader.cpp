#include "SensorReader.h"
#include "RingBuffer.h"
#include "SensorsIR.h"
#include "Sensors.h"

RingBuffer<int, 10> SensorReader::ledReadings[4];
RingBuffer<int, 10> SensorReader::echoReadings[2];

SensorReader::SensorReader()
{
    pollingRate = 0;
    timeSinceLastPoll = 0;
}

void SensorReader::update(long milliseconds)
{
    timeSinceLastPoll += milliseconds;
    if (timeSinceLastPoll > pollingRate)
    {
        timeSinceLastPoll -= pollingRate;
        Sensors* sensors = Sensors::get();
        for (IDSensorsIR i = 0; i < IR_NUM_SENSORS; ++i)
        {
            ledReadings[i].add(sensors->ir->getValue(i));
        }
        for(EchoSensorId i = 0; i < ECHO_NUM_SENSORS; ++i)
        {
            echoReadings[i].add(sensors->echo->getValue(i));
        }
    }
}

void SensorReader::setPollingRate(int pollingRate)
{
    this->pollingRate = pollingRate;
}

