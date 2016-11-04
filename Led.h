#ifndef Led_H
#define Led_H

#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

class Led {
    private:
        int led;
        bool state;
    public:
        Led(int led);
        Led(int led, bool state);

        int getLed();
        void setLed(int led);

        bool getState();

        void acender(int led);
        void apagar(int led);
        void inverter(int led);

        void acender(int led, int x);
        void piscar(int led, int x,int y);

        bool isAceso(int led);
        bool isPwm(int led);
};

#endif
