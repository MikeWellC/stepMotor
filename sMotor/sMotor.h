 
#ifndef MBED_SMOTOR_H
#define MBED_SMOTOR_H

#include "mbed.h"

class sMotor {
public:

    sMotor(PinName A0, PinName A1, PinName A2, PinName A3); //motor constructor

    void step(int num_steps, int direction, int speed);
    void anticlockwise();
    void clockwise();
    void stop();

private:
    uint8_t state;
    DigitalOut _A0;
    DigitalOut _A1;
    DigitalOut _A2;
    DigitalOut _A3;

};

#endif