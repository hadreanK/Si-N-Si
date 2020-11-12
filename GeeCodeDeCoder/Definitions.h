#ifndef GeeCodeDefs_h
#define GeeCodeDefs_h

#define MOTOR_FREQ 11 	// This is the frequency with which we'll update the motor 
						// positions, in Hz (hurts, doesn't it)
#define NUM_MOTORS 1 // This is the number of motors in the system (1 means 1 motor, 2 means 2 motors)

#define MOTOR_BUFFER_LEN 1000 // This is the number of elements in each array of motor positions that will be calculated at a time.
#define END_OF_MOVEMEMENT -1 //This is the value in the motor position buffer that will indicate the move has been completed
#define NUM_OF_BUFFERS 2 // We'll have at least two buffers so there is at least one two write to while the other is being read from. If it turns out the buffers are 

#endif

