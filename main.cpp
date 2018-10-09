/*
############################################
##           sMotor v0.1 Test Program     ##
##          created by Samuel Matildes    ##
############################################
        ---- sam.naeec@gmail.com -----
This library was made for 4-Phase Stepper Motors
I don't take any resposability for the damage caused to your equipment.

*/

#include "mbed.h"
#include "sMotor.h"


Serial pc(USBTX, USBRX);
sMotor motor(PE_13, PE_14, PE_8, PB_1); // creates new stepper motor: IN1, IN2, IN3, IN4
DigitalOut Enable(PA_8);
DigitalOut Reset(PE_6);
int step_speed = 1200 ; // set default motor speed
int numstep = 50 ; // defines full turn of 360 degree
//you might want to calibrate this value according to your motor


int main() {
     int sel;
     int i;
     Enable=1;
     Reset=1;
     Reset=0;
     Enable=0;
    //Credits
    printf("4 Phase Stepper Motor v0.1 - Test Program\r\n")

  while(1)
  {
        motor.step(numstep*10,0,step_speed);
        wait(1);
         motor.step(numstep*10,1,step_speed);
        wait(1);
      } 

    while (1) {
    printf("Default Speed: %d\n\r",step_speed);
    printf("1- 360 degree clockwise step\n\r");
    printf("2- 360 degree anticlockwise step\n\r");
    printf("3- 180 degree clockwise step\n\r");
    printf("4- 180 degree anticlockwise step\n\r");
    printf("5- Change Speed\n\r");
    scanf("%d",&sel);
        switch (sel)
        {
          case 1:{
                    motor.step(numstep,0,step_speed); // number of steps, direction, speed
                    break;
                    }

          case 2:{
                motor.step(numstep,1,step_speed);
                break;
                }

          case 3:{
                motor.step(numstep/2,0,step_speed);
                break;
                }

         case 4:{
                motor.step(numstep/2,1,step_speed);
                break;
                }

         case 5: {
                printf("Current Speed: %d\n\r", step_speed);
                printf("New speed: \n\r");
                pc.scanf("%d",&step_speed); // sets new speed
                break;
                }
            }
        
        
    }
}