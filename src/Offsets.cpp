#include "Offsets.h"
#include "Consts.h"

Offsets::Offsets(unsigned char id)
{
    switch (id)
    {
        case ID_TITAN:
            THRESHOLD_IR_BACK_LEFT = 2000;
            THRESHOLD_IR_BACK_RIGHT = 2000;
            THRESHOLD_IR_FRONT_LEFT = 500;
            THRESHOLD_IR_FRONT_RIGHT = 500;
            break;

        case ID_PHOBOS:
            THRESHOLD_IR_BACK_LEFT = 2000;
            THRESHOLD_IR_BACK_RIGHT = 2000;
            THRESHOLD_IR_FRONT_LEFT = 500;
            THRESHOLD_IR_FRONT_RIGHT = 500;
            break;
    }
}
