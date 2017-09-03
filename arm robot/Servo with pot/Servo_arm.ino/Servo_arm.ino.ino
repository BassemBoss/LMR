#include <Servo.h>

Servo myservo1; //shoulder 1 
Servo myservo2; // shoulder 2
Servo myservo3; //elbow 
Servo myservo4; // gripper

int potpin1 = 0; 
int potpin3 = 2;
int potpin4 = 3;
int val1; 
int val2; 
int val3; 
int val4; 

void setup()
{
myservo1.attach(6); 
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(11);
Serial.begin(9600);
}
void loop() {
{ 
val1 = analogRead(potpin1); 
val2 = map(val1, 0, 512, 180, 0); 
val1 = map(val1, 0, 512, 0, 180); 

myservo2.write(val2); 
myservo1.write(val1); 


val3 = analogRead(potpin3); 
val3 = map(val3, 0, 512, 0, 180); 
myservo3.write(val3); 


val4 = analogRead(potpin4); 
val4 = map(val4, 0, 512, 0, 180); 
myservo4.write(val4); 



delay(5); 
} 
}


