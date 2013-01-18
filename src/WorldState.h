#ifndef GUARD_WORLD_STATE
#define GUARD_WORLD_STATE

class WorldState
{
public:
    WorldState();
    bool isOpponentDetected;
    bool isOpponentBehind;
    long timeOpponentDetected;
    int lastOpponentDistance;
    bool irSensorsOn[4];
};

#endif
