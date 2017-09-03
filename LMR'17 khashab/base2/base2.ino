// Motor A pins"left motors" (enableA_l1 = enableA_l2 = enable motor, pinA1 = forward, pinA2 = backward)
int enableA_l1 = 10;
int enableA_l2 = 11;
int pinA1 = 7;
int pinA2 = 12;
int pinA3 = 3;
int pinA4 = 5;

//Motor B pins"right motors"  (enabledB_R1 = enableB_R2 = enable motor, pinB1 = forward, pinB2 = backward)
int enableB_R1 = 6;
int enableB_R2 = 9;
int pinB1 = 4;
int pinB2 = 2;
int pinB3 = 8;
int pinB4 = 13;
//joystick

int x_axis = 0 ;
int y_axis = 0 ;
int yPin = A1;
int xPin = A0;
int xPosition = 0;
int yPosition = 0;

void setup() {
 pinMode(enableA_l1, OUTPUT);
 pinMode(enableA_l2, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);
 pinMode(pinA3, OUTPUT);
 pinMode(pinA4, OUTPUT);
 pinMode(enableB_R1, OUTPUT);
 pinMode(enableB_R2, OUTPUT);
 pinMode(pinB1, OUTPUT);
 pinMode(pinB2, OUTPUT);
 pinMode(pinB3, OUTPUT);
 pinMode(pinB4, OUTPUT);
 pinMode(xPin, INPUT);
 pinMode(yPin, INPUT);
 

 }

 void loop() {
joystick();

if (y_axis==1 && x_axis==0)
  Forward();
/*else if (y_axis==1 && x_axis==1)
    forwardRight();
else if (y_axis ==1 && x_axis==-1)
    forwardLeft();*/
else if (y_axis ==0 && x_axis==1)
  turnRight();
else if (y_axis==-1 && x_axis==0)
  Backward();
else if (x_axis==-1 && y_axis==0)
  turnLeft();
else motorCoast();
/*else if (x_axis==1 && y_axis ==-1)
    backwardRight();
else if (y_axis ==-1 && x_axis==-1)
    backwardLeft();*/






 

}
 

 
 //motor A controls
void Forward()
{
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
 
void Backward()
{
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
{
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
{
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


void forwardRight (){
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 1);
  digitalWrite(pinB1, 0);
  digitalWrite(pinB2, 1);
  analogWrite(enableA_l1 ,255);
  analogWrite(enableA_l2 ,255);
  analogWrite(enableB_R1 ,128);
  analogWrite(enableB_R2 ,128);
}

void forwardLeft (){
  digitalWrite(pinA1, 0);
  digitalWrite(pinA2, 1);
  digitalWrite(pinB1, 0);
  digitalWrite(pinB2, 1);
  analogWrite(enableA_l1 ,128);
  analogWrite(enableA_l2 ,128);
  analogWrite(enableB_R1 ,255);
  analogWrite(enableB_R2 ,255);
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


void backwardLeft (){
  digitalWrite(pinA1, 1);
  digitalWrite(pinA2, 0);
  digitalWrite(pinB1, 1);
  digitalWrite(pinB2, 0);
  analogWrite(enableA_l1 ,255);
  analogWrite(enableA_l2 ,255);
  analogWrite(enableB_R1 ,128);
  analogWrite(enableB_R2 ,128);
}


void motorCoast()
{
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

void joystick (){
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
}

