#include "WorldState.h"

WorldState::WorldState()
{
    for (int i = 0; i < 4; ++i)
    {
        irSensorsOn[i] = false;
    }
    isOpponentDetected = false;
    isOpponentBehind = false;
    timeOpponentDetected = 0;
    timeOpponentDetectedBehind = 0;
    lastOpponentDistance = 0;
    lastOpponentDistanceBehind = 0;

}
