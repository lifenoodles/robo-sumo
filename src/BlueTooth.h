#ifndef GUARD_BLUETOOTH
#define GUARD_BLUETOOTH

#include <Arduino.h>

enum MessageConstants
{
    MSG_ECHO_FRONT = 0,
    MSG_ECHO_BACK = 1,
    MSG_IR_FRONT_LEFT = 2,
    MSG_IR_FRONT_RIGHT = 3,
    MSG_IR_BOTTOM_LEFT = 4,
    MSG_IR_BOTTOM_RIGHT = 5,
    MSG_REMOTE_CONTROL_TOGGLE = 6,
};

class BlueTooth
{
public:
    BlueTooth();
    static BlueTooth* get();
    String read();
    void print(String string);
    void println(String string);
    void logDebug(String string);
    void report(int milliseconds);
    void setDebugging(bool isDebug);
    void setReporting(bool isReporting);
    void setEnabled(bool isEnabled);
    void setReportingInterval(int interval);
private:
    int reportIntervalTime;
    int timeSinceLastReport;
    bool isReporting;
    bool isDebugging;
    String lastMessage;
    static BlueTooth* instance;
};

#endif
