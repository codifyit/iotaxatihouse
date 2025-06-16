using namespace std;
#include <Arduino.h>
#include <Axconfig.h>

Axconfig::Axconfig(){
    axDisplay.init(); 
    axDisplay.backlight();//initialize LCD
    axDisplay.setCursor(0, 0);
    axDisplay.print(F("Hola!"));
    axDisplay.setCursor(0, 1);
    axDisplay.print(F("IES Axati Home"));
    //set ports of two servos to digital 9 and 10
    axServo1.setDigPinMode(0,9,INPUT);
    axServo1.attach(9);
    axServo1.write(0);
    axServo2.setDigPinMode(0,10,INPUT);
    axServo2.attach(10);
    axServo2.write(0);
    axButton1.setDigPinMode(0,4, INPUT);
    axButton2.setDigPinMode(0,8, INPUT);
    axInfrared.setDigPinMode(0,2, INPUT);
    axGas.setAnaPinMode(0,A0,INPUT);
    axHygro1.setAnaPinMode(0,A3,INPUT);
    axHygro2.setAnaPinMode(0,A2,INPUT);
    axFan.setDigPinMode(0,6,OUTPUT);
    axFan.setDigPinMode(1,7,OUTPUT);
    axLight.setAnaPinMode(0,A1,INPUT);
    axLed1.setDigPinMode(0,13,OUTPUT);
    axLed2.setDigPinMode(0,5,OUTPUT);
    axRelay.setDigPinMode(0,12,OUTPUT);
}

void Axconfig::writeDigital(int digIO, int state){
    digitalWrite(digIO,state);
}
int Axconfig::readDigital(int digIO){
    return digitalRead(digIO);
}
void Axconfig::writeAnalog(int analogIO, int state){
    analogWrite(analogIO, state);
}
int Axconfig::readAnalog(int analogIO){
    return analogRead(analogIO);
}