#include "LED.h"

LED::LED(int led){
    this -> led = led;
}

LED::LED(int led, bool state){
    this -> led = led;
    this -> state = state;
}

LED::getLed(){
    return this -> led;
}

LED::setLed(int led){
    this -> led = led;
    pinMode(led,OUTPUT);
}

LED::getState(int led){
    return digitalRead(this -> led);
}

LED::acender(int led){
    digitalWrite(led, HIGH);
    this -> state = true;
}

LED::apagar(int led){
    digitalWrite(led, LOW);
    this -> state = false;
}

LED::acender(int led, int x){
    analogWrite(led,x);
    this -> state = true;
}

LED::piscar(int led, int x,int y){
    while(x > 0){
        digitalWrite(led, HIGH);
        delay(y);
        digitalWrite(led,LOW);
        delay(y);
        x--;
    }
}

LED::isAceso(int led){
    return getState(led);
}
 LED::isPwn(int led){
    if(led == 11 || led == 10 || led == 6 || led ==5 || led == 3){
        return true;
    } else {
        return false;
    }
 }
