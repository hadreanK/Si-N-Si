#include "GeeCodeDeCoder.cpp"

// DEFINITIONS AND GLOBAL VARIABLES //
GCodeStuff gCode;

void setup() {
  // put your setup code here, to run once:
gCode.readSelector = 1;
gCode.motorBuffer[1][2][1] = 8675309;
}

void loop() {
  // put your main code here, to run repeatedly:

}
