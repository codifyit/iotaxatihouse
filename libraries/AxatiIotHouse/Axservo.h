using namespace std;
#include <Servo.h>
#include <Axactuator.h>
#ifndef Axservo_h
#define Axservo_h         

class Axservo:public Axactuator{
    private: 
        Servo servo;
    public:
        void attach(int pin);
        void write(int what);
};
#endif