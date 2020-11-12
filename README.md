# Si-N-Si
 A repository for any and all code for our CNC router project.

The way we've discussed this project so far, there may be at least 2 chunks of code that end up here:
	1. The code that takes in G-code, and turns it in to motor movements
	2. The code that acts as an HMI to create G-code and control the machine
Other possibilities include:
	3. Something to monitor the progress of the machine, such as a webcam that is streamed to a website.

Over-arching program steps:
	1. Process one-dimensional linear moves
	2. Process three-dimensional linear moves
	3. Process three-dimensional linear and circular moves


For the code that takes in G-Code and makes motor movements, we might want to oranize it with these functions:
	- Calculates the next array of motor positions, given the point on the path. (I'm thinking we have two arrays of motor positions, one that's being written to and one that's being read from.)
		*Maybe instead of it being fixed length, it's just the length of the next move.
			** What if it's a huge number though?
		* Maybe it calculates just one command at a time (line/arc/wait), and then inserts -1's afterwards. The program that's telling the motors what to do will switch which array it reads from when it finds a -1
	- Calculates XY positions as a function of time, given G-Codes
	- Calculates the next relative XY positions if the next move is a line
		* What if it goes beyond the end of the next set of positions?
	- Calculates the next relative XY positions if the next move is an arc
	- Calculates the next relative XY positions if the next move is a wait
	- A watchdog that will make sure the motors don't try to go too fast
	
Things to define:
	- Inch to motor counts for each motor
	- Motor step frequency
	- Number of motor positions per array
	- Maximum number of steps per time interval (maybe 1?)(Do you even know how stepper motors work, bro?)
	

- Have a calibrations file that gets loaded each time the code is compiled

Style guidelines:
1. CamelCase please! For functionNames please start with lowercase, variableNames start with lowercase and StructureNames start with uppercase. In theory if this ever becomes object oriented, ClassNames begin with uppercase but instanceNames begin lowercase.
2. Please indent code to show structure. Kind of like you're writing in python, but you don't have to go to that extent.
3. Please make tabs four (4) spaces long.
4. Defintions should be ALL_CAPS with underscores to separate words
	a. Please write a comment next to each definition to describe what it does.
5. Please write a brief comment in the header file for each function describing it's inputs, outputs, and purpose.
6. Please title major blocks of code in all caps with leading and trailing backslashes, like:
	// THIS BLOCK OF CODE SUCKS //



