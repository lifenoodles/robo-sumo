#ifndef GUARD_MANEUVER
#define GUARD_MANEUVER

enum MANEUVER_MOTOR_MOVES
{
    MANEUVER_RIGHT_FORWARD = 0,
    MANEUVER_RIGHT_BACKWARD = 1,
    MANEUVER_LEFT_FORWARD = 2,
    MANEUVER_LEFT_BACKWARD = 3,
    MANEUVER_BOTH_FORWARD = 4,
    MANEUVER_BOTH_BACKWARD = 5,
};

class Maneuver
{
public:
    Maneuver(int moveCount,
        int moveArray[], long timeArray[]);
    void execute(long milliseconds);
    bool isDone();
private:
    void moveMotor(int moveId);
    long moveTimer;
    int moveCount;
    int moveIndex;
    int* moves;
    long* times;
};

#endif
