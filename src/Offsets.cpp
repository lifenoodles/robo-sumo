#include "Offsets.h"
#include "Consts.h"
#include "SensorsIR.h"

unsigned int Offsets::thresholds[4];

Offsets::Offsets(unsigned char id)
{
    switch (id)
    {
        case ID_TITAN:
            thresholds[IR_BACK_LEFT] = 2000;
            thresholds[IR_BACK_RIGHT] = 2000;
            thresholds[IR_FRONT_LEFT] = 500;
            thresholds[IR_FRONT_RIGHT] = 500;
            break;

        case ID_PHOBOS:
            thresholds[IR_BACK_LEFT] = 2000;
            thresholds[IR_BACK_RIGHT] = 2000;
            thresholds[IR_FRONT_LEFT] = 500;
            thresholds[IR_FRONT_RIGHT] = 500;
            break;
    }
}
