#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <inttypes.h>
#include <Axactuator.h>
#ifndef Axdisplay_h
#define Axdisplay_h
//Set the communication address of I2C to 0x27, display 16 characters every line, two lines in total

class Axdisplay: public Axactuator{
    private:
        LiquidCrystal_I2C mylcd;
    public:
        Axdisplay();
        void init();
        void setCursor(uint8_t, uint8_t);
        void backlight();
        void print(String);
        void clear();
};
#endif