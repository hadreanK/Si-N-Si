#ifndef GeeCodeDeCoder_h
#define GeeCodeDeCoder_h

#include "Definitions.h"

// Class DEFINITIONS //
class MotionData {
	private:
		long int m_currentStep;
		int m_pinDir;
		int m_pinStep;
		int m_pinMS1;
		int m_pinMS2;
		int m_stepSize;
		
	public:
		// Public Variables
		long int currentStep;
		int tBuffer1[BUFFER_SIZE]; // the time buffer in ms
		int tBuffer2[BUFFER_SIZE]; // the second time buffer in ms
		int xBuffer1[BUFFER_SIZE]; // the position buffer in steps
		int xBuffer2[BUFFER_SIZE]; // the alternate position buffer in steps
		
		//Constructor
		MotionData(int,int,int,int);
		
		// Methods
		void parseGCode(void);
		void setupOneMotor(void);
		void setStepSize(int);	
			// This method will set the step size, from 1/8 to 1
			// The input is the number of eighths of a step, i.e.:
			// stepSize = 1 -> 1/8 step
			// stepSize = 4 -> 1/2 step
			// If not given 1,2,4 or 8, it sets it to 8

		void moveMotor(long int);
			// This method will move the motor a certain number of steps
			// Negative steps are in the negative direciton
		void stepMotor();
			// This will move the motor one step in its current direction

}; // MotionData Class definition

#endif

