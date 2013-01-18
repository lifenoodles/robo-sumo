#ifndef GUARD_WORLD_STATE
#define GUARD_WORLD_STATE

class WorldState
{
public:
    WorldState();
    bool isOpponentDetected;
    bool isOpponentBehind;
    long timeOpponentDetected;
    long timeOpponentDetectedBehind;
    int lastOpponentDistance;
    int lastOpponentDistanceBehind;
    bool irSensorsOn[4];
};

#endif
