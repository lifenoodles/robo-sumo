#include "WorldState.h"

WorldState::WorldState()
{
    for (int i = 0; i < 4; ++i)
    {
        irSensorsOn[i] = false;
    }
    isOpponentDetected = false;
    timeSinceOpponentDetected = 0;
    lastOpponentDistance = 0;
}
