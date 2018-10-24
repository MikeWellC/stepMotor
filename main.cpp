/* Step Motor Control 
By modular-2 Team 2018/10/24
*/
#include "mbed.h"
#include "sMotor.h"
Serial pc(USBTX, USBRX);
// creates new stepper motor: A, B, A-, B- speed ,polar =0;positive 1 negtive
 sMotor motor(PE_13, PE_14, PE_8, PB_1,400,0); 
DigitalOut Enable(PA_8);
DigitalOut Reset(PE_6);
DigitalOut led(PC_6);
int main() {
     Enable=1;
     Reset=1;
     Reset=0;
     Enable=0;
    printf("2 Phase Stepper Motor Control v0.2\r\n");
  while(1)
  {
        motor.step(720,150);//rotation 360 
        wait(0.3);
        motor.step(-720,150);  
        wait(0.3);
        led=!led;
      } 

}