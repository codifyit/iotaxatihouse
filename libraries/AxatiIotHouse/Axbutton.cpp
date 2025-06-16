using namespace std;
#include <Axbutton.h>

void Axbutton::incPushCount(){
    this->pushCount++;
}
int Axbutton::getPushCount(){
    return this->pushCount;
}
void Axbutton::resetPushCount(){
    this->pushCount=0;
}