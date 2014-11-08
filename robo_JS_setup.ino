
int forwardInPin = A0;               // variable forwardInPin to analog input 0
int backInPin = A2;                  // variable backInPin to analog input 2
int leftOutPin = 8;                  // variable forwardInPin to analog input 0
int rightOutPin = 12;                // variable forwardInPin to analog input 0
int led = 13;


void setup()
{
  pinMode(forwardInPin, INPUT);      // sets the analog pin as input
  pinMode(leftOutPin, OUTPUT);       // sets the pin as output
  pinMode(rightOutPin, OUTPUT);      // sets the pin as output
  pinMode(led, OUTPUT);
}

void loop() //forward for 1 sec
{
    //forward
    analogWrite(forwardInPin, 255);       // turns on forward power
    digitalWrite(leftOutPin, LOW);     // left pulls in
    digitalWrite(rightOutPin, LOW);    // right pulls in
    delay(500);                         // waits for a second
    
    // indecator light
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    
        //right 90
    analogWrite(forwardInPin, 255);       // turns on forward power
    digitalWrite(leftOutPin, HIGH);     // left pulls in
    digitalWrite(rightOutPin, LOW);    // right pulls in
    delay(428);                         // time of turn
    
        // indecator light X2 to indicate rest
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

    
        //    wait
    analogWrite(forwardInPin, 0);       // turns on forward power
    digitalWrite(leftOutPin, LOW);     // left pulls in
    digitalWrite(rightOutPin, LOW);    // right pulls in
    delay(5000);                         // waits for 5 seconds
    
    // indecator light
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

    
        //    left 90
    analogWrite(forwardInPin, 255);
    digitalWrite(leftOutPin, LOW);     // left does not pull in
    digitalWrite(rightOutPin, HIGH);    // right pulls in
    delay(428);                         // time of turn
    
        // indecator light X2 to indicate rest
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    
        //    wait
    analogWrite(forwardInPin, 0);       // turns on forward power
    digitalWrite(leftOutPin, LOW);     // left dosen't pulls in
    digitalWrite(rightOutPin, LOW);    // right dosen't pulls in
    delay(5000);                       // waits for 5 seconds
    
    // indecator light
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    
}

