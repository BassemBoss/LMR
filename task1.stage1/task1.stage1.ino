/*
    * File        : Stage1.Task1
    * Author      : bassem
    * Date        : 23/8/2017
*/
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

//pin define
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
int l=0,r=0,f=0; //f  forword distance and r reverse distance and l left distance
long int ms=0; // time that arduino is on 
short int n=1; //n=1 link 1 -- n=2 link 2 -- n=3 link3 -- n=4 link4 and end task 1
while (n>4)
{ 
  l=sonarleft.ping_cm();
  r=sonarright.ping_cm();
  f=sonarfront.ping_cm();
  ms=millis()/1000;
  if (f>10&&ms>10&&f<200) // if The distance is correct
  {
    linefollow();
  } 
 else if (f<10&&ms>10&&(n==1||n==2))
 {
  while (f>10&&ms>10)
  {
  forwardRight ();
  }
  n++;
 }
 else if (f<10&&ms>10&&(n==3))
 {
  while (f>10&&ms>10)
  {
  forwardLeft ();
  }
  n++;
 }
}
Forward();
delay (10000);
motorCoast();
//end of task1;
}


void linefollow()
{ 
  int l=0,r=0,f=0;
  int ms=0;
 f=sonarfront.ping_cm();
 ms=millis()/1000;
 while (f>10&&ms>10)
  { 
 l=sonarleft.ping_cm();
 r=sonarright.ping_cm();
 f=sonarfront.ping_cm();
 ms=millis()/1000;
 //check and follow
 if (l==25&&r==25)
 {
  Forward();
 }
 else if (l<25&&r>25)
 {
  forwardRight();
 }
 else if (l>25&&r<25)
 {
  forwardLeft ();
 } //end check and follow 
  } // you should turn
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
 
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
}

void forwardRight ()
{ 
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 1);
  digitalWrite(pinB1, 0);
  digitalWrite(pinB2, 1);
  analogWrite(enableA_l1 ,255);
  analogWrite(enableA_l2 ,255);
  analogWrite(enableB_R1 ,128);
  analogWrite(enableB_R2 ,128);
}

void forwardLeft ()
{
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 1);
  digitalWrite(pinB1, 0);
  digitalWrite(pinB2, 1);
  analogWrite(enableA_l1 ,128);
  analogWrite(enableA_l2 ,128);
  analogWrite(enableB_R1 ,255);
  analogWrite(enableB_R2 ,255);
}

void motorCoast()
{ // stop robot
 digitalWrite(pinA1, 0);
 digitalWrite(pinA2, 0);
 digitalWrite(pinA3, 0);
 digitalWrite(pinA4, 0);
 digitalWrite(pinB1, 0);
 digitalWrite(pinB2, 0);
 digitalWrite(pinB3, 0);
 digitalWrite(pinB4, 0);
 analogWrite(enableA_l1 ,0);
 analogWrite(enableA_l2 ,0);
 analogWrite(enableB_R1 ,0);
 analogWrite(enableB_R2 ,0);
}
