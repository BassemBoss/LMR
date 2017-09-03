#include <Servo.h>
Servo shoulder;  
Servo shoulder2;
Servo elbow;
Servo gripper;
#define joyx A0 
#define joyy A1 
int joyval=0;

void setup() {
  // put your setup code here, to run once:
shoulder.attach(3);
shoulder2.attach(5);
elbow.attach(6);
gripper.attach(10);
pinMode (4,INPUT);

shoulder.writeMicroseconds(544);
 shoulder2.writeMicroseconds(544);
 elbow.writeMicroseconds(444);
 gripper.writeMicroseconds(344);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val ;
joyval=analogRead(joyx);
shoulder.write(map(joyval,0,1023,0,180));
joyval=analogRead(joyx);
shoulder2.write(map(joyval,0,1023,180,0));
joyval=analogRead(joyy);
elbow.write(map(joyval,0,1023,0,180));
delay(15);
val=analogRead(4);
if(val==1)
gripper.write(50);
else if (val==0)
gripper.write(120);
}
