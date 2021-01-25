#ifndef GeeCodeDeCoder_cpp
#define GeeCodeDeCoder_cpp

// LIBRARY INCLUDES
#include <Arduino.h>
#include "Definitions.h"
#include "GeeCodeDeCoder.h"

// FUNCTIONS
MotionData::MotionData(int pinDir,int pinStep, int pinMS1, int pinMS2){
	m_currentStep = 53;
	currentStep = 57;
	m_pinDir = pinDir;
	m_pinStep = pinStep;
	m_pinMS1 = pinMS1;
	m_pinMS2 = pinMS2;
} // Constructor, I think

void MotionData::parseGCode(void){}//parseGCode
void MotionData::setupOneMotor(void){
	// Set each pin as an output
	pinMode(m_pinDir,OUTPUT);
	pinMode(m_pinStep,OUTPUT);
	pinMode(m_pinMS1,OUTPUT);
	pinMode(m_pinMS2,OUTPUT);
}//setupOneMotor

void MotionData::setStepSize(int stepSize){
	m_stepSize = stepSize;
switch (stepSize){
  case 2: // 1/4 -> 0,1
    digitalWrite(m_pinMS1,LOW);
    digitalWrite(m_pinMS2,HIGH);
    break;
  case 4: // 1/2 -> 1,0
    digitalWrite(m_pinMS1,HIGH);
    digitalWrite(m_pinMS2,LOW);
    break;
  case 8: // 1/1 -> 0,0
    digitalWrite(m_pinMS1,LOW);
    digitalWrite(m_pinMS2,LOW);
    break;
  default: // otherwise set it to 1/8, i.e. 1,1
    digitalWrite(m_pinMS1,HIGH);
    digitalWrite(m_pinMS2,HIGH);
    break;
	} // switch
} //setStepSize

void MotionData::moveMotor(long int steps){
	// Preparation is key.
	long int absSteps;
	absSteps = abs(steps)*m_stepSize;
	
	// Set the direction
	if(steps>0){
		digitalWrite(m_pinDir,HIGH);
	}else{
	digitalWrite(m_pinDir,LOW);
	}
	
	// Move the motor
	for(long int i=0;i<(absSteps);i++){
		digitalWrite(m_pinStep,HIGH);
		delayMicroseconds(MICROSECOND_DELAY_STEP);
		digitalWrite(m_pinStep,LOW);
		delayMicroseconds(MICROSECOND_DELAY_STEP);
	}//for i 
	
} // moveMotor

void MotionData::stepMotor(){
	digitalWrite(m_pinStep,HIGH);
	//delayMicroseconds(MICROSECOND_DELAY_STEP);
	digitalWrite(m_pinStep,LOW);
	//delayMicroseconds(MICROSECOND_DELAY_STEP);
} // stepMotor

void MotionData::motorControl(){
	// Get the x and t buffers
	// interpolate between each one 
}//motorControl
#endif
