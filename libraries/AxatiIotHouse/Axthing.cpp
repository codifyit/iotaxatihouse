using namespace std;
#include <string.h>
#include <Axthing.h>
Axthing::Axthing(){

}
void Axthing::setDigPinMode(int pinIndex, int pin, int mode){
    this->digPines[pinIndex]=Axpin(mode,0);
    pinMode(pin,mode);
}
void Axthing::setAnaPinMode(int pinIndex, int pin, int mode){
    this->digPines[pinIndex]=Axpin(mode,1);
    pinMode(pin,mode);
}
void Axthing::digWrite(int pinIndex, int value){
    digitalWrite(digPines[pinIndex].getPinNumber(),value);
}
int Axthing::digRead(int pinIndex){
    return digitalRead(digPines[pinIndex].getPinNumber());
}
int Axthing::anaRead(int pinIndex){
    return analogRead(anaPines[pinIndex].getPinNumber());
}
void Axthing::anaWrite(int pinIndex, int value){
    analogWrite(anaPines[pinIndex].getPinNumber(),value);
}