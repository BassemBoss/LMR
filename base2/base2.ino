//Motor A pins"left motors"
#define enableA_l1   3
#define enableA_l2   5
#define pinA1   0  // reverse 1
#define pinA2   1  // forword 1
#define pinA3   2  // revesr 2
#define pinA4   4  // forword 2

//Motor B pins"right motors"
#define enableB_R1   6
#define enableB_R2   9
#define pinB1   7
#define pinB2   8
#define pinB3   12
#define pinB4   13
//joystick

int x_axis = 0 ;
int y_axis = 0 ;
#define yPin   A1 
#define xPin   A2 
int xPosition = 0;
int yPosition = 0;
/*
const int s0 = 8;  
const int s1 = 7;  
const int s2 = 12;  
const int s3 = 13;  
const int out = 5;   
// LED pins connected to Arduino
int redLed = 52;  
int greenLed = 50;  
int blueLed = 51;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0; 
*/ 

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
 /*
 pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);
  */
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



/*
color();
 if (red < blue && red < green && red < 20)
  {  
   
   digitalWrite(redLed, HIGH); // Turn RED LED ON 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW);  
  }  

  else if (blue < red && blue < green)   
  {  
    
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  }  

  else if (green < red && green < blue)  
  {  
     
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }  
  else{
    
  }
  delay(300);   
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  digitalWrite(blueLed, LOW);  





*/

}
 /*
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
 */
 //motor A controls
void Forward()
{
 digitalWrite(pinA1, 0);  // reverse 1
 digitalWrite(pinA2, 1);  // forword 1
 digitalWrite(pinA3, 0);  // reverse 2
 digitalWrite(pinA4, 1);  // forword 2 
 digitalWrite(pinB1, 0);  // reverse 1
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

