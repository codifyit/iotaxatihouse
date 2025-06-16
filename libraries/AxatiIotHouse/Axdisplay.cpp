#include <Axdisplay.h>

Axdisplay::Axdisplay(){
    //mylcd(0x27,16,2);
}
void Axdisplay::init(){
    mylcd.init();
}
void Axdisplay::backlight(){
    mylcd.backlight();
}
void Axdisplay::setCursor(uint8_t x, uint8_t y){
    mylcd.setCursor(x,y);
}
void Axdisplay::print(String msg){
    mylcd.print(msg);
}
void Axdisplay::clear(){
    mylcd.clear();
}