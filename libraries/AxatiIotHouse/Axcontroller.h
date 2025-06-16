#include <Arduino.h>
#include <Axbutton.h>
#include <Axdisplay.h>
#include <Axservo.h>
#include <Axbuzzer.h>
#include <Axhygro.h>
#include <Axgas.h>
#include <Axlight.h>
#include <Axfan.h>
#include <Axconfig.h>
#ifndef Axcontroller_h
#define Axcontroller_h
 
class Axcontroller
{
    private:
        int command;   //char code command
        Axconfig aXconfig;
    public:
        Axcontroller();
        void doorAction();
        void gasAction();
        void rainAction();
        void lightAction();
        void soilAction();
        void infraredAction();
        int getCommand();
        void request(int command);
        void start();
};
#endif
