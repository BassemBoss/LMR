#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
//arm robot pins"left motors"
#define enableA_l1   3
#define enableA_l2   5
#define pinA1   0  // reverse 1
#define pinA2   1  // forword 1
#define pinA3   2  // revesr 2
#define pinA4   4  // forword 2

void setup() 
{
  myservo1.attach(6); // shoulder 1
  myservo2.attach(9); // shoulder 2
  myservo3.attach(10); // albow
  myservo4.attach(11); // gripper
  // z axe motor
 pinMode(enableA_l1, OUTPUT);
 pinMode(enableA_l2, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);
 pinMode(pinA3, OUTPUT);
 pinMode(pinA4, OUTPUT); 
  
  Serial.begin(9600);
}
void loop()
{ while (Serial.available())
   {
 unsigned short int  servopos= Serial.read();
 unsigned short int  servopos1= Serial.read();
 unsigned short int  realservo= (servopos1*256)+servopos;
 if (realservo>=1000 && realservo<1177)
 {
  short int servol = realservo;
  servol = map (servol,1000,1177,0,177); 
  myservo1.write (servol); 
  myservo2.write ((177-servol)); 
 }
 else if (realservo>=2000 && realservo<2177)
 {
  short int servo2 = realservo;
  servo2 =map (servo2,2000,2177,0,177); 
  myservo3.write (servo2); 
 }
 else if (realservo>=3000 && realservo<3177)
 {
  short int servo3 = realservo;
  servo3 = map (servo3,3000,3177,0,177); 
  myservo4.write (servo3); 
 }
else if (servopos=='Z')
Forward();
 else if (servopos=='M')
Backward();


}
}
void Forward()
{
 digitalWrite(pinA1, 0);  // reverse 1
 digitalWrite(pinA2, 1);  // forword 1
 digitalWrite(pinA3, 0);  // reverse 2
 digitalWrite(pinA4, 1);  // forword 2 
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
}
 
void Backward()
{
 digitalWrite(pinA1, 1);
 digitalWrite(pinA2, 0);
 digitalWrite(pinA3, 1);
 digitalWrite(pinA4, 0);
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
}

