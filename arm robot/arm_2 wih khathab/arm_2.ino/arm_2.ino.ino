#include <Servo.h>

Servo shoulder;  
Servo shoulder2;
Servo elbow;
Servo gripper;
 
#define  yPin  A1
#define xPin  A0
short int x=0 ,y=0;
short int xPosition = 0;
short int yPosition = 0;
short int x_axis = 0 ;
short int y_axis = 0 ;  
#define zPinright 0
#define zpinleft 1

int angle1Array[13]={10,20,30,40,50,60,70,80,90,100,110,120,130};
int angle2Array[13]={175,165,145,135,125,110,100,90,80,65,50,40,25};
int angle3Array[13]={170,165,145,135,125,115,95,85,75,55,40,35,25};

short int angle1_A=10,angle1_B,angle2_A=175,angle2_B,angle3_A=170,angle3_B;

void setup() 
{
shoulder.attach(10);  
shoulder2.attach(11);
elbow.attach(9);
gripper.attach(6);
Serial.begin(9600);
shoulder.writeMicroseconds(544);
 shoulder2.writeMicroseconds(544);
 elbow.writeMicroseconds(444);
 gripper.writeMicroseconds(344);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPinright, INPUT);
  pinMode(zpinleft, INPUT);
}

void loop()
{  
angle1_B=angle1Array[x];
angle2_B=angle2Array[x];
angle3_B=angle3Array[x];

joystick ();

shoulder1_mov();
shoulder2_mov();
elbow_mov();

}
void joystick ()
{
 xPosition  = analogRead(xPin) ;
 yPosition = analogRead(yPin) ; 
if ( xPosition >511 )
 x_axis = 1 ;
else if ( xPosition < 170 ) 
x_axis = -1 ; 
 else if ( xPosition >= 170 && xPosition <= 511) 
x_axis = 0 ;

if ( yPosition >500 )
 y_axis = 1 ;
else if ( yPosition < 170 ) 
 y_axis = -1 ; 
else if ( yPosition >= 170 && yPosition <= 500) 
 y_axis = 0 ;

 x+=x_axis;
 y+=y_axis;

 if (x<0)x=0;
 if (x>12)x=12;
}

void shoulder1_mov()
{
  for(;angle1_A<angle1_B;angle1_A++)
   { 
    shoulder.write(angle1_A);
   }

  for(;angle1_A>angle1_B;angle1_A--)
   { 
    shoulder.write(angle1_A);
   }
}
void shoulder2_mov()
{
  for(;angle2_A<angle2_B;angle2_A++)
   { 
    shoulder2.write(angle2_A);
   }
 
  for(;angle2_A>angle2_B;angle2_A--)
   { 
    shoulder2.write(angle2_A);
   }  
}
void elbow_mov()
{
 for(;angle3_A<angle3_B;angle3_A++)
   { 
    elbow.write(angle3_A);
   }
 
 for(;angle3_A>angle3_B;angle3_A--)
   { 
    elbow.write(angle3_A);
   }  
}
