/*
    * File        : Stage1.Task1
    * Author      : bassem
    * Date        : 6/9/2017
*/
// task 1 variables
short int right_base_speed=175;
short int left_base_speed=175; 
short int right_motor_speed , left_motor_speed ;  
// end decleration 
#include <NewPing.h> // ultrasnic lib

//Motor A pins"left motors"
#define enableA_l1   10
#define enableA_l2   11
#define pinA1   22
#define pinA2   23
#define pinA3   24
#define pinA4   25

//Motor B pins"right motors"
#define enableB_R1   6
#define enableB_R2   9
#define pinB1   26
#define pinB2   27
#define pinB3   28
#define pinB4   29

//pin define of 3 ultrasonics
#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8
#define MAX_DISTANCE 200

NewPing sonarleft(trigPin1, echoPin1, MAX_DISTANCE);
NewPing sonarright(trigPin2, echoPin2, MAX_DISTANCE);
NewPing sonarfront(trigPin3, echoPin3, MAX_DISTANCE);

void setup()
{
//declaration of motors a :
 pinMode(enableA_l1, OUTPUT);
 pinMode(enableA_l2, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);
 pinMode(pinA3, OUTPUT);
 pinMode(pinA4, OUTPUT);
 
//declaration of motors b :
 pinMode(enableB_R1, OUTPUT);
 pinMode(enableB_R2, OUTPUT);
 pinMode(pinB1, OUTPUT);
 pinMode(pinB2, OUTPUT);
 pinMode(pinB3, OUTPUT);
 pinMode(pinB4, OUTPUT);
 
Serial.begin (9600);
}

void loop() 
{ 
  task1();
  Serial.println("strart task1");
}

void task1 ()
{
while (1)
{
short int kp =20 , motor_speed , last_error ;
float l=0,r=0,f=0; //f  forword distance and r reverse distance and l left distance
long int ms=0; // time that arduino is on 
  l=sonarleft.ping_cm();
  r=sonarright.ping_cm();
  f=sonarfront.ping_cm();
  int error_task1 = l-r ;
  if (error_task1 ==0 ) // if The distance is correct
  {
    Forward();
  }
 else 
 {
  right_motor_speed = right_base_speed + motor_speed ;
  left_motor_speed = left_base_speed - motor_speed ;
  motor_turns ();
 }
 
 motor_speed = kp * error_task1 ;
 last_error = error_task1 ;
}
}

 //motors controls
void Forward()
{ //Forward with high speed
 digitalWrite(pinA1, 0);
 digitalWrite(pinA2, 1);
 digitalWrite(pinA3, 0);
 digitalWrite(pinA4, 1);
 digitalWrite(pinB1, 0);
 digitalWrite(pinB2, 1);
 digitalWrite(pinB3, 0);
 digitalWrite(pinB4, 1);
 
 analogWrite(enableA_l1, left_base_speed); 
 analogWrite(enableA_l2, left_base_speed);
 analogWrite(enableB_R1, right_base_speed);
 analogWrite(enableB_R2, right_base_speed);
}

void motor_turns ()
{ 
  
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 1);
  digitalWrite(pinB1, 0);
  digitalWrite(pinB2, 1);
  analogWrite(enableA_l1 ,left_motor_speed);
  analogWrite(enableA_l2 ,left_motor_speed);
  analogWrite(enableB_R1 ,right_motor_speed);
  analogWrite(enableB_R2 ,right_motor_speed);
}
