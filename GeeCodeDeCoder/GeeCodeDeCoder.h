#ifndef GeeCodeDeCoder_h
#define GeeCodeDeCoder_h

// STRUCTURES //
typedef struct {
	long motorBuffer[NUM_MOTORS][MOTOR_BUFFER_LEN][NUM_OF_BUFFERS];
	// This array contains the upcoming motor positions
	// The value in the first dimension determines which motor we're referring to.
	// The value in the second dimension selects which position of the buffer we'd like to read.
	// The value in the third dimension determines whcih buffer to read from.
	
	int readSelector = 0; // This value shows which buffer we're reading from currently. 
} GCodeStuff;

typedef struct {
	long motorPosition[NUM_MOTORS]; 
} MotorStates;

// FUNCTION DEFINITIONS //


#endif

