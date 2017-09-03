/*
    * File        : 12c master code
    * Author      : bassem
    * Date        : 27/8/2017
*/
#include <Servo.h>
#include <Wire.h>


Servo shoulder;  
Servo shoulder2;
Servo elbow;
Servo gripper;

short int angle_A,angle_B;

void setup() {
shoulder.attach(10);  
shoulder2.attach(11);
elbow.attach(9);
gripper.attach(6);
Wire.begin(); // I2 C 


  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
}


void loop() 
{ 
  moves :
   Serial.println("enter 1 to move base  /nenter 2 to move arm with angles ");
   short int x;
   x = Serial.read();
   if (x==1)
   send_to_slave_base();
   else if (x==2)
   moveARM();
}

 void send_to_slave_base (void) {
 if(Serial.available())
  {
   char data = Serial.read();
  Wire.beginTransmission(0); // port 0
   Wire.write(data); 
  //send from master ..
  Wire.endTransmission(); 
  }
 }

 void moveARM (void){
  Serial.println("enter position you need to move in angle_A");
 angle_A=Serial.read();
 Serial.println("enter position you need to move in angle_B");
 angle_B=Serial.read();
shoulder1_mov(angle_A,angle_B);
shoulder2_mov(angle_A,angle_B);
elbow_mov(angle_A,angle_B);
 }

 
void shoulder1_mov(int angle_A,int angle_B){
 if (angle_A<angle_B) {

  for(angle_A=0;angle_A<=angle_B;angle_A++)
   { shoulder.write(angle_A);
   /*
       delay(100);
       Serial.println("shoulder's 1 angle:");
       Serial.println(angle_A);
       */
       }

 }
else if (angle_A>angle_B) 
   for(angle_B=0;angle_B<=angle_A;angle_B++)
   { 
    shoulder.write(angle_B);
   /*
       delay(100);
   Serial.println("shoulder's 1 angle:");
   Serial.println(angle_B);
   */
   }
}
  
  
  void shoulder2_mov(int angle_A,int angle_B){
  if (angle_A<angle_B) {

 for(angle_A=0;angle_A<=angle_B;angle_A++)
   { shoulder2.write(angle_A);
   /*
    delay(10);
    Serial.println("shoulder's 2 angle:");
   Serial.println(angle_A);
   */
    }
 }
else if (angle_A>angle_B) {
   for(angle_B=0;angle_B<=angle_A;angle_B++)
   { shoulder2.write(angle_B);
   /*
       delay(10);
   Serial.println("shoulder's 2 angle:");
   Serial.println(angle_B);
   */
   }  
  }
  }
void elbow_mov(int angle_A,int angle_B){
  if (angle_A<angle_B){
 for(angle_A=0;angle_A<=angle_B;angle_A++)
   { elbow.write(angle_A);
   /*
    delay(15);
    Serial.println("elbow angle:");
   Serial.println(angle_A);
   */
   
    }
 }
else if (angle_A>angle_B){ 
   for(angle_B=0;angle_B<=angle_A;angle_B++)
   { elbow.write(angle_B);
   /*
       delay(15);
   Serial.println("elbow angle:");
   Serial.println(angle_B);
   */
   }  
}
}
