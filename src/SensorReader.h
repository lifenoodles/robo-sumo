#ifndef GUARD_SENSOR_READER
#define GUARD_SENSOR_READER

#include "RingBuffer.h"

class SensorReader
{
public:
    SensorReader();
    void update(long delta);
    void setPollingRate(int pollingRate);
private:
    void processIrData(long delta);
    void processEchoData(long delta);
    int pollingRate;
    long timeSinceLastPoll;
    RingBuffer<int, 1> ledReadings[4];
    RingBuffer<int, 5> echoReadings[2];
    int frontSortBuffer[5];
    int backSortBuffer[5];
};

#endif
