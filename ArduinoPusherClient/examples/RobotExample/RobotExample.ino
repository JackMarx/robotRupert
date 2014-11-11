#include <Logging.h>

#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>
#include <PusherClient.h>
#include <WiFi.h>

char ssid[] = "Dev Bootcamp"; //  your network SSID (name) 
char pass[] = "igeekallweek";  

int status = WL_IDLE_STATUS;
#define LOGLEVEL LOG_LEVEL_DEBUG

//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte mac[] = { 0x78, 0xC4, 0xE, 0x2, 0x51, 0x28 };
PusherClient client;
Servo leftServo; 
Servo rightServo; 
int led = 8;

void setup() {
  Log.Init(LOGLEVEL, 38400L);
   
  pinMode(led, OUTPUT);
  
  pinMode(2,OUTPUT);
  leftServo.attach(2);
  
  pinMode(3, OUTPUT);
  rightServo.attach(3);

  leftServo.write(95);
  rightServo.write(95);
  
  Serial.begin(9600);
//  if (Ethernet.begin(mac) == 0) {
//    Serial.println("Init Ethernet failed");
//    for(;;)
//      ;
//  }
  
   if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
  Serial.println("Connected to wifi");
  
  if(client.connect("a32b9aab7196cd0862d2")) {
    client.bind("forward", moveForward);
    client.bind("backward", moveBackward);
    client.bind("turn_left", turnLeft);
    client.bind("turn_right", turnRight);
    client.bind("stop", stopMoving);
    client.subscribe("robot_channel");
    Serial.println("You win");
  }
  else {
    Serial.println("\nSad face");
    while(1) {}
  }
}

void loop() {
//  if (client.connected()) {
    client.monitor();
//  }
//  else {
//    leftServo.write(95);
//    rightServo.write(95);
//  }
}

void moveForward(String data) {
  digitalWrite(led, HIGH);
  delay(1000);
//  leftServo.write(0);
//  rightServo.write(180);
}

void moveBackward(String data) {
  digitalWrite(led, LOW);
  delay(1000);
  // leftServo.write(180);
  // rightServo.write(0);
}

void turnLeft(String data) {
  leftServo.write(0);
  rightServo.write(0);
}

void turnRight(String data) {
  leftServo.write(180);
  rightServo.write(180);
}

void stopMoving(String data) {
  leftServo.write(95);
  rightServo.write(95);
}