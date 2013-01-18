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
    void processIrData(long milliseconds);
    void processEchoData(long milliseconds);
    int pollingRate;
    long timeSinceLastPoll;
    static RingBuffer<int, 1> ledReadings[4];
    static RingBuffer<int, 5> echoReadings[2];
};

#endif
