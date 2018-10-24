/*
############################################
##           sMotor v0.1 Library          ##
##          created by Samuel Matildes    ##
############################################
        ---- sam.naeec@gmail.com -----
This library was made for 4-Phase Stepper Motors
I don't take any resposability for the damage caused to your equipment.

*/
#ifndef MBED_SMOTOR_H
#define MBED_SMOTOR_H

#include "mbed.h"

class sMotor {
public:
     /*  
     stepsPerTurn half step mode (360/1.8)*2   
     polar=0  positiveoutput 
     polar=1 negtive output 
     */
    sMotor(PinName A0, PinName A1, PinName A2, PinName A3,int stepsPerTurn,uint8_t polarMask); 
    void step(float degree, int speed);
    void clockwise();
    void stop();

private:
 
    int steps_turn;
    int delay;
    DigitalOut _A0;
    DigitalOut _A1;
    DigitalOut _A2;
    DigitalOut _A3;
    int state;
    uint8_t polar;
};

#endif