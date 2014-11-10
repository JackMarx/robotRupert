
int forwardInPin = A0;                         // variable forwardInPin to analog input 0
int leftOutPin = 8;                            // variable leftOutPin to digital 8
int rightOutPin = 12;                          // variable rightOutPin to digital 12
int led = 13;                                  // varaible led to digital 13



void setup()
{
  pinMode(forwardInPin, INPUT);                // sets the analog pin as input
  pinMode(leftOutPin, OUTPUT);                 // sets the pin as output
  pinMode(rightOutPin, OUTPUT);                // sets the pin as output
  pinMode(led, OUTPUT);                        // sets the pin as output
}


void loop() //list of instructions
{   
   moveForward();
   moveForward();
   moveForward();
   turnLeft();
   moveForward();
   moveForward();
   moveForward();
   turnLeft();
   moveForward();
   moveForward();
   moveForward();
   turnLeft();
   moveForward();
   moveForward();
   moveForward();
   turnLeft();
   stopMovement();
   stopMovement();
   indicatorLight();
   indicatorLight();
   
   moveForward();
   turnRight();
   moveForward();
   turnRight();
   moveForward();
   turnRight();
   moveForward();
   turnRight();
   stopMovement();
   stopMovement();
   indicatorLight();
   indicatorLight();
}

void moveForward() //move forward 1 foot
{
    analogWrite(forwardInPin, HIGH);         // turns on forward power
    digitalWrite(leftOutPin, LOW);           // left pulls in
    digitalWrite(rightOutPin, LOW);          // right pulls in
    delay(1000);                             // waits for a second
};

void turnRight() // turn right 90 degrees
{
    analogWrite(forwardInPin, HIGH);         // turns on forward power
    digitalWrite(leftOutPin, HIGH);          // left pulls in
    digitalWrite(rightOutPin, LOW);          // right stops pulling in
    delay(1250);                             // time of turn
};

void turnLeft() // turn left 90 degrees
{
    analogWrite(forwardInPin, HIGH);          // turns on forward power
    digitalWrite(leftOutPin, LOW);            // left stops pulling in
    digitalWrite(rightOutPin, HIGH);          // right pulls in
    delay(1450);                              // time of turn 
};

void stopMovement() // stop robot
{
    pinMode(forwardInPin, INPUT);                // sets the analog pin as input
    digitalWrite(leftOutPin, LOW);            // left stops pulling in
    digitalWrite(rightOutPin, LOW);           // right stops pulling in
    delay(1000);
};

void indicatorLight() //flash the indicator light
{
    digitalWrite(led, HIGH);                  // turn the LED on (HIGH is the voltage level)
    delay(1000);                          // wait for a second
    digitalWrite(led, LOW);                   // turn the LED off by making the voltage LOW
    delay(1000);                          // wait for a second 
};




