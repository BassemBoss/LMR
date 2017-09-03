#include<math.h>
#include <Servo.h>

Servo shoulderServo1; 
Servo shoulderServo2;
Servo elbowServo;
Servo gripServo;   
#define L1 120 
#define L2 68 
#define L3 15 
#define Rad2Deg 57.295779  
#define Deg2Rad 0.017453
int  yPin = A1;
int xPin = A0;
int xPosition = 0;
int yPosition = 0;
int x_axis = 0 ;
int y_axis = 0 ;
int x=150 ;
int y=50; 

float L,theta1,theta2,theta2bar,theta3,beta1,beta2,beta3 ;

void setup() {
  // put your setup code here, to run once:
shoulderServo1.attach(9);
shoulderServo2.attach(10);
elbowServo.attach(11);
gripServo.attach(12) ; 
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
theta1=theta2=theta3=beta1=beta2=beta3 = 0 ; 

joystick();
  
theta3 = thetathree (x,y);
beta3 = 90 - theta3 ;
L = sqrt(sq(L2) + sq(L3) - 2*L2*L3*cos(Deg2Rad * theta3)) ; //data type conversion is nedded cuz cos o/p is double

theta2 = thetatwo(x,y,L) ; 
beta2 = 30 + theta2 ; 

theta1 = thetaOne(x,y,theta2,L);
beta1 = 180 - (theta1 + 30 ) ;

Serial.print("x= ");Serial.println(x);
Serial.print("y= ");Serial.println(y);
Serial.print("beta1= ");Serial.println(beta1);
Serial.print("beta2= ");Serial.println(beta2);
Serial.print("beta3= ");Serial.println(beta3);
delay(10000);

shoulderServo1.write(beta1);                 
shoulderServo2.write(180 - beta1);
elbowServo.write(beta2);  
gripServo.write(beta3);  
  delay(15);
  
}

float thetathree (int x , int y){
  
int x1 = x- L3;
float z = sqrt(sq(x1) + sq(y) );

double phi1 = atan2(x1 , y ) * Rad2Deg ; 

float phi2opp = ( sq(z)+ sq(L2)-sq(L1) ) / (2*z*L2);  
double phi2 = acos (phi2opp) * Rad2Deg ;
float theta3 = 360 - (phi1 + phi2 + 90 );
return theta3 ; 
 }
 
float thetatwo (int x , int y , int L){
float Tn = sq(x) + sq(y) - sq(L1) - sq(L)  ;
float Tm = 2*L1*L;
float T=Tn/Tm;
float upper = sqrt(1 - sq(T) ) ;
theta2bar = atan2(upper,T)  * Rad2Deg ; 
theta2bar = 0- theta2bar;
float up =sq(L2)+sq(L)-sq(L3);
float dn =2*L2*L;
float division = up/dn;
float phi3 = acos(division)*Rad2Deg;
float theta2 =phi3 - theta2bar;
  return theta2  ;
  }

float thetaOne (int x , int y ,float theta2 ,int L) {
  float k2 = L* sin(Deg2Rad * theta2bar);
  float k1 = L1 + L* cos(Deg2Rad * theta2bar) ;
  float theta1 = atan2(y,x) * Rad2Deg - atan2(k2,k1) * Rad2Deg ; 
  return theta1 ;
}

void joystick (){
 xPosition  = analogRead(xPin) ;
 yPosition = analogRead(yPin) ; 
 
if ( xPosition >511 )
 x_axis = 1 ;
else if ( xPosition < 170 ) 
x_axis = -1 ; 
 else if ( xPosition >= 170 && xPosition <= 340) 
x_axis = 0 ;

if ( yPosition >500 )
 y_axis = 1 ;
else if ( yPosition < 170 ) 
 y_axis = -1 ; 
else if ( yPosition >= 170 && yPosition <= 340) 
 y_axis = 0 ;

 x = x + x_axis;
 y = y + y_axis;
}

