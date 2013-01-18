#include "Offsets.h"
#include "Consts.h"
#include "SensorsIR.h"

unsigned int Offsets::thresholds[4];

Offsets::Offsets(unsigned char id)
{
    switch (id)
    {
        case ID_TITAN:
            thresholds[IR_BACK_LEFT] = 3000;
            thresholds[IR_BACK_RIGHT] = 3000;
            thresholds[IR_FRONT_LEFT] = 500;
            thresholds[IR_FRONT_RIGHT] = 500;
            closeDistanceThreshold = 5;
            farDistanceThreshold = 50;
            opponentTimeout = 2000;
            rearDangerThreshold = 8;
            break;

        case ID_PHOBOS:
            thresholds[IR_BACK_LEFT] = 3000;
            thresholds[IR_BACK_RIGHT] = 3000;
            thresholds[IR_FRONT_LEFT] = 500;
            thresholds[IR_FRONT_RIGHT] = 500;
            closeDistanceThreshold = 5;
            farDistanceThreshold = 50;
            opponentTimeout = 2000;
            rearDangerThreshold = 8;
            break;
    }
}
