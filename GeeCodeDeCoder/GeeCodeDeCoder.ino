#include <avrTimers.h>

#include "GeeCodeDeCoder.h"

// DEFINITIONS AND GLOBAL VARIABLES //
MotionData simpleMotor(53,52,50,51);
long int counter = 0;

void setup() {
Serial.begin(9600);
simpleMotor.setupOneMotor();
simpleMotor.setStepSize(8);
atMega2560_T3(0b101, round(15625/MOTOR_FREQ)); //16MHz, 1024 scalar, means it ticks every 1/15626 of a second 
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(simpleMotor.currentStep);
//simpleMotor.moveMotor(0);
delay(1000);
//simpleMotor.moveMotor(-0);
Serial.println(counter);
} //loop

ISR(TIMER3_COMPA_vect){ // This is the timer for motor movement
  
  counter++;
 // simpleMotor.stepMotor();
} //ISR TIMER3
