using namespace std;
#ifndef Axpin_h
#define Axpin_h

class Axpin{
    public:
        Axpin();
        Axpin(int mode, int type);
        int getPinMode();
        int getPinType();
        int getPinValue();
        void setPinMode(int mode);
        void setPinType(int type);
        void setPinValue(int value);
        int getPinNumber();
    private:
        int mode;
        int value;
        int type;
        int number;
};
#endif