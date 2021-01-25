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
		long int m_startTime;
		
	public:
		// Public Variables
		long int currentStep;
		long int xPos; // This is the current x position of the motor in steps
		int tBuffer1[BUFFER_SIZE]; // the time buffer in 1/10s
		int tBuffer2[BUFFER_SIZE]; // the second time buffer in 1/10s
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
		void motorControl();
			// This will control 1 motor along the 
		void makeTestProgram();
			// This will make a test program
			// RN it's set up to make a 1D sine wave for a single motor to follow
		void startMotion();
			// This will start the current loaded motion program
}; // MotionData Class definition

// Other stuff


#endif

