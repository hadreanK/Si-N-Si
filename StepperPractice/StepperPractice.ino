#define START_PIN 22
int currentPos = 0;

bool wireToPos[4][8] = {
    {true, true, false, false, false, false, false, true},
    {false, true, true, true, false, false, false, false},
    {false, false, false, true, true, true, false, false},
    {false, false, false, false, false, true, true, true}
    }; // wireToPos

void setup() {
  // put your setup code here, to run once:
for (int i=0; i<4; i++){
    pinMode(START_PIN + 2*i,OUTPUT);
    digitalWrite(START_PIN + 2*i, LOW);
    }// for i
} // setup

void loop() {

    for (int i=0; i<4; i++){
        digitalWrite(START_PIN + 2*i, wireToPos[i][currentPos]);
        } // for i
    delay(100);
    currentPos = (currentPos+1)%8;
    
} // loop
