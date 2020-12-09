// This script is for Hardware assginment submission dated 04.12.2020

// Author:Arpan Mathe, Charng Shin Chen 
// Faculty - Angel Munoz, Matthew Gordon
// Copyright: Copyright 2020, IAAC
// Credits: [Institute for Advanced Architecture of Catalonia - IAAC, Advanced Architecture group]
// Version: 1.0.0
// Email: arpan.mathe@students.iaac.net, charngshin.chen@students.iaac.net
// Status: Hardware Assignment Submission - 04.12.2020

// This code is for controlling Servo motor and CNC spindle with ABB IRB 140 Robotic arm

#include <Servo.h>

Servo myservo;
int pos = 0; //servo initual position
int motor = 3; // motor pin assigned
boolean currentstate = false; // define current boolean state
int inpinmotor1 = 6; // aruino pin connecting to robotic arm optocoupler for motor
int inpinservo = 5; // aruino pin connecting to robotic arm optocoupler for servo
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //read serial
  Serial.println("Start");
  pinMode(motor, OUTPUT); //define pin connected to robotic arm optocoupler as input pin for motor actuation
  pinMode(inpinmotor1, INPUT);
 
  myservo.attach(9); //define servo pin
  pinMode(inpinservo, INPUT); //define pin connected to robotic arm optocoupler as input pin for servo actuation
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean robotinput1 = !digitalRead(inpinmotor1); // to read input from robot
  boolean robotinput6 = !digitalRead(inpinservo); // to read input from robot

  if (robotinput1 == true) {
    analogWrite(motor, 255); delay(10); analogWrite(motor, 250); //for motor to turn ON when robot sends signal
    Serial.println("You have turned on the MOTOR at 1 speed!!");
    Serial.print("The Motor was off for ");
    Serial.print(count);
    Serial.println(" seconds");
    //Serial.println("If you want to switch it off, simply enter 0");
    count = 0;
  }
  
  if (robotinput1 == false) {
    digitalWrite(motor, LOW);
    Serial.println("You have turned off the MOTOR!!"); //for motor to turn OFF when robot sends signal
    Serial.print("The Motor was on for ");
    Serial.print(count);
    Serial.println(" seconds");
    //Serial.println("If you want to switch it on, simply enter any range from 1 to 4");
    count = 0;
  }

  if (robotinput6 == true) {
    myservo.write(10); //for servo to turn when robot sends signal
    Serial.println("You have turned on the SERVO!!");
    Serial.print("The Servo was off for ");
    Serial.print(count);
    Serial.println(" seconds");
    //Serial.println("If you want to switch it off, simply enter O or o!");
    count = 0;
  }
  if (robotinput6 == false) {
    myservo.write(60); //for servo to turn when robot sends signal
    Serial.println("You have turned off the Servo!!"); 
    Serial.print("The Servo was on for ");
    Serial.print(count);
    Serial.println(" seconds");
    //Serial.println("If you want to switch it on, simply enter S or s!");
    count = 0;
  }
  delay(1000);
  count += 1;
}
