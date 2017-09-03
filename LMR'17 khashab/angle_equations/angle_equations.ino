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
int x=150 ,y=50 ; 
float theta1,theta2,theta3,beta1,beta2,beta3,L ;
 

void setup() {
 
shoulderServo1.attach(9);
shoulderServo2.attach(10);
elbowServo.attach(11);
gripServo.attach(12) ; 
Serial.begin(9600); 

}

void loop() {
  
theta1 = theta2 = theta3 = 0 ;  
theta3 = thetathree (x,y);
beta3 = 90 - theta3 ;
L = sqrt(sq(L2) + sq(L3) - 2*L2*L3*cos(Deg2Rad * theta3)) ; //data type conversion is nedded cuz cos o/p is double

theta2 = thetatwo(x,y,theta3,L) ; 
beta2 = 30 + theta2 ; 

theta1 = thetaOne(x,y,theta2,L);
beta1 = 180 - (theta1 + 30 ) ;

Serial.println(theta1);
Serial.println(theta2);
Serial.println(theta3);
delay(1000);

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
return( theta3 ); 
 }
 
float thetatwo (int x , int y , float theta3 , int L){
float T = (sq(x) + sq(y) - sq(L1) - sq(L)) / 2*L1*L ;
float upper = sqrt(1 - sq(T) ) ;
float theta2 = atan2(upper,T)  * Rad2Deg ; 
  return (theta2 ) ;
  }

float thetaOne (int x , int y ,float theta2 ,int L) {
  float k2 = L* sin(Deg2Rad * theta2);
  float k1 = L1 + L* cos(Deg2Rad * theta2) ;
  float theta1 = atan2(x,y) * Rad2Deg - atan2(k2,k1) * Rad2Deg ; 
  return ( theta1) ;
}
  
   
