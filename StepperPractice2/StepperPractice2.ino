#define PIN_DIR 53
#define PIN_STEP 52
#define PIN_MS1 50
#define PIN_MS2 51
#define TRAVEL_DIST 2000
#define STEPS_PER_REV 4096

int counter = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(PIN_DIR,OUTPUT);
pinMode(PIN_STEP,OUTPUT);
pinMode(PIN_MS1,OUTPUT);
pinMode(PIN_MS2,OUTPUT);
pinMode(LED_BUILTIN,OUTPUT);

digitalWrite(PIN_DIR,LOW);
digitalWrite(PIN_STEP,LOW);
digitalWrite(LED_BUILTIN,HIGH);
setStepSize(2);
}

void loop() {
  // put your main code here, to run repeatedly:
// Switch direction
digitalWrite(PIN_DIR,!digitalRead(PIN_DIR));
for(long int i=0; i<=TRAVEL_DIST; i++){
  //digitalWrite(PIN_STEP,HIGH); // Step
  digitalWrite(PIN_STEP,LOW);  // Reset
  delayMicroseconds(1000);
}// For i

//setStepSize(2^(counter%4));
counter++;
digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
delay(100);
} // loop

void setStepSize(int stepSize){
// This function will set the step size, from 1/8 to 1
// The input is the number of eighths of a step, i.e.:
// stepSize = 1 -> 1/8 step
// stepSize = 4 -> 1/2 step
// If not given 1,2,4 or 8, it sets it to 8

switch (stepSize){
  case 2: // 1/4 -> 0,1
    digitalWrite(PIN_MS1,LOW);
    digitalWrite(PIN_MS2,HIGH);
    break;
  case 4: // 1/2 -> 1,0
    digitalWrite(PIN_MS1,HIGH);
    digitalWrite(PIN_MS2,LOW);
    break;
  case 8: // 1/1 -> 0,0
    digitalWrite(PIN_MS1,LOW);
    digitalWrite(PIN_MS2,LOW);
    break;
  default:
    digitalWrite(PIN_MS1,HIGH);
    digitalWrite(PIN_MS2,HIGH);
    break;
}// switch stepSize

} // setStepSize
