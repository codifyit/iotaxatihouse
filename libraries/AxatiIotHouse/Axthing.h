#include "Arduino.h"
#include <Axpin.h>
#ifndef Axthing_h
#define Axthing_h
class Axthing
{
    private:
        Axpin digPines[3];
        Axpin anaPines[3];

    public:
        Axthing();
        void setDigPinMode(int pinIndex,int pin, int mode);
        void setAnaPinMode(int pinIndex,int pin, int mode);
        void digWrite(int pin, int value);
        int digRead(int pin);
        int anaRead(int pin);
        void anaWrite(int pin, int value);
        int getDigPinMode(int pinIndex);
        int getDigPinNum(int pinIndex);
        int getAnaPinMode(int pinIndex);
        int getAnaPinNum(int pinIndex);
};
#endif