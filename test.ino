#include <Servo.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


Servo Myservo;
int i = 0;
int pos=0;
int LED = 13;
int Button = 12;

// Initialization of all components
void setup(){
  // Init USB serial port for debugging
  Serial.begin(9600);
  Myservo.attach(6);  // Connect D6 of Arduino with PWM signal pin of servo motor
  // Init serial port for DFPlayer Mini
  SoftwareSerial mySoftwareSerial(0, 1); // RX, TX
  DFRobotDFPlayerMini player;
  player.volume(30);
  player.play(1);
  pinMode(LED,OUTPUT);
  pinMode(Button,INPUT);
  for(int i = 0; i <=2000; i++) {
    blink();
  }
}

void loop(){
  if(digitalRead(Button)==LOW){
  digitalWrite(LED, LOW);
  Myservo.write(90);
  } 
  else (digitalRead(Button) == HIGH);
    digitalWrite(LED, HIGH);
}

void blink(){
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
}
