#include <Axbutton.h>
#include <Axdisplay.h>
#include <Axservo.h>
#include <Axbuzzer.h>
#include <Axhygro.h>
#include <Axgas.h>
#include <Axlight.h>
#include <Axfan.h>
#include <Axled.h>
#include <Axrelay.h>
#ifndef Axconfig_h
#define Axconfig_h
 
class Axconfig
{
    private:

    public:
        enum Things{
            LCD,FAN,GAS,INFRARED,LIGHT,SERVO,BUZZER,HYGRO,BUTTON, LED, RELAY
        };
        Axconfig();
        void writeDigital(int digIO, int mode);
        int readDigital(int digIO);
        void writeAnalog(int digIO, int mode);
        int readAnalog(int digIO);

        Axdisplay axDisplay;
        Axservo axServo1;
        Axservo axServo2;
        Axlight axLight;
        Axhygro axHygro1;
        Axhygro axHygro2;
        Axbuzzer axBuzzer;
        Axgas axGas;
        Axfan axFan;
        Axbutton axButton1;
        Axbutton axButton2;
        Axinfrared axInfrared;
        Axled axLed1;
        Axled axLed2;
        Axrelay axRelay;
};
#endif