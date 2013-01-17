/*#ifndef GUARD_COMMAND_QUEUE
#define GUARD_COMMAND_QUEUE

#include "RingBuffer.h"

struct RemoteCommand
{
    char command;
    char argument;
};

class CommandQueue
{
public:
    void add(char command, char argument);
    RemoteCommand next();
    RemoteCommand hasNext();
private:
    RingBuffer<char, 20> arguments;
    RingBuffer<char, 20> commands;
};

#endif
*/
