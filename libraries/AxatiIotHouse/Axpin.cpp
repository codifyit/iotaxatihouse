using namespace std;
#include <Axpin.h>
Axpin::Axpin(){}
Axpin::Axpin(int mode, int type){
    this->mode = mode;
    this->type = type;
}
int Axpin::getPinMode(){
    return this->mode;
}
int Axpin::getPinType(){
    return this->type;
}
int Axpin::getPinValue(){
    return this->value;
}
void Axpin::setPinMode(int mode){
    this->mode = mode;
}
void Axpin::setPinType(int type){
    this->type = type;
}
void Axpin::setPinValue(int value){
    this->value = value;
}
int Axpin::getPinNumber(){
    return this->number;
}