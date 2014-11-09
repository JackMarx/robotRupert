
int forwardInPin = A0;                         // variable forwardInPin to analog input 0
int leftOutPin = 5;                            // variable leftOutPin to digital 8
int rightOutPin = 6;                          // variable rightOutPin to digital 12
int led = 13;                                  // varaible led to digital 13
int turn90 = 500;                              // variable turn90
int moveTime = 500;                            // variable moveTime
int waitTime = 1000;                           // variable waitTime
int forwardPower = HIGH;                        // variable forwardPower
int turnPower = 255;                           // variable turnPower



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
    turnRight();
//    stopMovement();
    delay(waitTime);
    indicatorLight();
    indicatorLight();
    delay(waitTime);
}

void moveForward() //move forward 1 foot
{
    analogWrite(forwardInPin, forwardPower);   // turns on forward power
    digitalWrite(leftOutPin, LOW);             // left pulls in
    digitalWrite(rightOutPin, LOW);            // right pulls in
    delay(moveTime);                           // waits for a second
}

void turnRight() // turn right 90 degrees
{
    analogWrite(forwardInPin, turnPower);      // turns on forward power
    digitalWrite(leftOutPin, HIGH);            // left pulls in
    digitalWrite(rightOutPin, LOW);            // right stops pulling in
    delay(turn90);                             // time of turn 
}

void turnLeft() // turn left 90 degrees
{
    analogWrite(forwardInPin, turnPower);      // turns on forward power
    digitalWrite(leftOutPin, LOW);             // left stops pulling in
    digitalWrite(rightOutPin, HIGH);           // right pulls in
    delay(turn90);                             // time of turn 
}

void stopMovement() // stop robot
{
//    analogWrite(forwardInPin, HIGH);             // turns off forward power
    digitalWrite(leftOutPin, LOW);            // left stops pulling in
    digitalWrite(rightOutPin, LOW);           // right stops pulling in
}

void indicatorLight() //flash the indicator light
{
    digitalWrite(led, HIGH);                  // turn the LED on (HIGH is the voltage level)
    delay(waitTime);                          // wait for a second
    digitalWrite(led, LOW);                   // turn the LED off by making the voltage LOW
    delay(waitTime);                          // wait for a second 
}




