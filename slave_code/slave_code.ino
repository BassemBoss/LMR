/*
    * File        : 12c Slave code
    * Author      : bassem
    * Date        : 27/8/2017
*/
//Motor A pins"left motors"
#define enableA_l1   3
#define enableA_l2   5
#define pinA1   0
#define pinA2   1
#define pinA3   2
#define pinA4   4

//Motor B pins"right motors"
#define enableB_R1   6
#define enableB_R2   9
#define pinB1   7
#define pinB2   8
#define pinB3   12
#define pinB4   13

#include <Wire.h>

void setup() {
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
 
 Wire.begin(0); // port 0
  
 Wire.onReceive(receiveEvent);
}

void loop() 
{
}

void receiveEvent(void) {
  while (1 < Wire.available()) { 
   char data = Wire.read(); 
   if (data == 'F')
  {
   Forward() ;
 
  }
  else if (data == 'B' )
  {
   Backward() ;

  }
   else if (data == 'L' )
   {
  turnLeft ();
  
   }
  else if (data == 'R' )
  {
  turnRight() ;
 
  }
  else if (data == 'G' )
  {
  forwardLeft () ;

  }
  else if (data == 'I' )
  {
  forwardRight () ;

  }
    else if ( data == 'H' )
    {
  backwardLeft () ;

    }
     else if ( data == 'J' )
     {
 backwardRight () ;

     }
   else if (data == 'S' )
   {
 motorCoast() ;

   }
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
void Backward()
{ //Backward with high speed
 digitalWrite(pinA1, 1);
 digitalWrite(pinA2, 0);
 digitalWrite(pinA3, 1);
 digitalWrite(pinA4, 0);
 digitalWrite(pinB1, 1);
 digitalWrite(pinB2, 0);
 digitalWrite(pinB3, 1);
 digitalWrite(pinB4, 0);
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
}

void turnLeft()
{ //turnLeft with high speed
 digitalWrite(pinA1, 1);
 digitalWrite(pinA2, 0);
 digitalWrite(pinA3, 1);
 digitalWrite(pinA4, 0);
 digitalWrite(pinB1, 0);
 digitalWrite(pinB2, 1);
 digitalWrite(pinB3, 0);
 digitalWrite(pinB4, 1);
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
}

void turnRight()
{ //turnRight with high speed
 digitalWrite(pinA1, 0);
 digitalWrite(pinA2, 1);
 digitalWrite(pinA3, 0);
 digitalWrite(pinA4, 1);
 digitalWrite(pinB1, 1);
 digitalWrite(pinB2, 0);
 digitalWrite(pinB3, 1);
 digitalWrite(pinB4, 0);
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
}
void backwardRight (){
  digitalWrite(pinA1, 1);
  digitalWrite(pinA2, 0);
  digitalWrite(pinB1, 1);
  digitalWrite(pinB2, 0);
  analogWrite(enableA_l1 ,128);
  analogWrite(enableA_l2 ,128);
  analogWrite(enableB_R1 ,255);
  analogWrite(enableB_R2 ,255);
}

void backwardLeft ()
{ 
  digitalWrite(pinA1, 1);
  digitalWrite(pinA2, 0);
  digitalWrite(pinB1, 1);
  digitalWrite(pinB2, 0);
  analogWrite(enableA_l1 ,255);
  analogWrite(enableA_l2 ,255);
  analogWrite(enableB_R1 ,128);
  analogWrite(enableB_R2 ,128);
}
