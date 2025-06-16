using namespace std;
#include <Axactuator.h>
#include <Arduino.h>
#ifndef Axbutton_h
#define Axbutton_h
class Axbutton:public Axactuator{
    private:
        int pushCount;
    public:
        int getPushCount();
        void incPushCount();
        void resetPushCount();
};
#endif