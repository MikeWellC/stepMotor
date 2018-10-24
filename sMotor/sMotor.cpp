 
#include "sMotor.h"

#include "mbed.h"



sMotor::sMotor(PinName A0, PinName A1, PinName A2, PinName A3,int stepsPerTurn,uint8_t polarMask) : _A0(A0), _A1(A1), _A2(A2), _A3(A3) { // Defenition of motor pins
  
    state=0;
    steps_turn=stepsPerTurn;
    polar=polarMask;
    _A0=0^polar;
    _A1=0^polar;
    _A2=0^polar;
    _A3=0^polar;
}


void sMotor::clockwise() { // rotate the motor 1 step anticlockwise 
  

        switch (state) { // activate the ports A0, A2, A3, A3 in a binary sequence for steps
            case 0: {
                _A0=0^polar;//1;
                _A1=0^polar;//1;
                _A2=0^polar;//1;
                _A3=1^polar;//0;
            }
            break;
            case 1: {
                _A0=0^polar;//1;
                _A1=0^polar;//1;
                _A2=1^polar;//0;
                _A3=1^polar;//0;
            }
            break;
            case 2: {
                _A0=0^polar;//1;
                _A1=0^polar;//1;
                _A2=1^polar;//0;
                _A3=0^polar;//1;
            }
            break;
            case 3: {
                _A0=0^polar;//1;
                _A1=1^polar;//0;
                _A2=1^polar;//0;
                _A3=0^polar;//1;
            }
            break;
            case 4: {
                _A0=0^polar;//1;
                _A1=1^polar;//0;
                _A2=0^polar;//1;
                _A3=0^polar;//1;
            }
            break;
            case 5: {
                _A0=1^polar;//0;
                _A1=1^polar;//0;
                _A2=0^polar;//1;
                _A3=0;//1;
            }
            break;
            case 6: {
                _A0=1^polar;//0;
                _A1=0^polar;//1;
                _A2=0^polar;//1;
                _A3=0^polar;//1;
            }
            break;
            case 7: {
                _A0=0^polar;//0;
                _A1=0^polar;//1;
                _A2=0^polar;//1;
                _A3=1^polar;//0;
            }
            break;
        }
    
      
      
        wait_us(delay); // wait time defines the speed 
  
}
  
void sMotor::step(float degree,  int speed) {
    bool direction;
     int count=0; 
     int  steps;
     if (degree>0) {
         state=0;
         direction=true;
         } else 
         {
             state=7;
             degree=-degree;
             direction=false;
         }    
   
    steps=(int)((degree/360)*steps_turn);
    delay=1000000/((speed/60)*steps_turn);//wait in us  
    if (direction) // turn clockwise
        do {
             clockwise();
            state++;
            if (state==7) state=0;
            count++;
        } while (count<steps); // turn number of steps applied 
    else //turn anticlockwise
        do {
            clockwise();
              state--;
            if (state==0) state=7;
            count++;
        } while (count<steps);// turn number of steps applied 

}
void sMotor::stop()
{
     _A0=0^polar;
    _A1=0^polar;
    _A2=0^polar;
    _A3=0^polar;
    }