#ifndef GUARD_OFFSETS
#define GUARD_OFFSETS

class Offsets
{
public:
    Offsets(unsigned char id);
    static unsigned int thresholds[4];
    int closeDistanceThreshold;
    int farDistanceThreshold;
    int opponentTimeout;
};

#endif
