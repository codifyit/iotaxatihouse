using namespace std;
#include <Servo.h>
#include <Arduino.h>
#include <Axservo.h>
/*Servo servo_10;
Servo servo_9;
String servo1;              //string type variable servo1
String servo2;              //string type variable */
void Axservo::attach(int pin){
    this->servo.attach(pin);
}
void Axservo::write(int what){
    this->servo.write(what);
}