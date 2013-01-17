#ifndef GUARD_SENSOR_READER
#define GUARD_SENSOR_READER

#include "RingBuffer.h"

class SensorReader
{
public:
    SensorReader();
    void update(long milliseconds);
    void setPollingRate(int pollingRate);
private:
    void processSensorData();
    int pollingRate;
    int timeSinceLastPoll;
    static RingBuffer<int, 10> ledReadings[4];
    static RingBuffer<int, 10> echoReadings[2];
};

#endif
