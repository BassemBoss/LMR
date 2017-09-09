//#include <SoftwareSerial.h>
//Motor A pins"left motors"
#define enableA_l1    4
#define enableA_l2    5
#define pinA1   23
#define pinA2   25
#define pinA3   27
#define pinA4   29

//Motor B pins"right motors"
#define enableB_R1   2
#define enableB_R2   3
#define pinB1   22
#define pinB2   24
#define pinB3   26
#define pinB4   28
//SoftwareSerial BTSerial(1, 0); // RX | TX
void setup() {
  // put your setup code here, to run once:
//BTSerial.begin(4800);
Serial.begin(9600);
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
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available())
  {
  char data = Serial.read();
  if (data == 'F')
  {//delay(1000);
   Forward() ;
    //Serial.println("f");
  }
  else if (data == 'B' )
  {//delay(1000);
   Backward() ;
   //Serial.println("b");
  }
   else if (data == 'L' )
   {//delay(1000);
  turnLeft ();
  //Serial.println("l");
   }
  else if (data == 'R' )
  {//delay(1000);
  turnRight() ;
  //Serial.println("r");
  }
  else if (data == 'G' )
  {//delay(1000);
  forwardLeft () ;
 // Serial.println("g");
  }
  else if (data == 'I' )
  {//delay(1000);
  forwardRight () ;
  //Serial.println("i");
  }
    else if ( data == 'H' )
    {//delay(1000);
  backwardLeft () ;
  //Serial.println("h");
    }
     else if ( data == 'J' )
     {//delay(1000);
 backwardRight () ;
  //Serial.println("j");
     }
   else if (data == 'S' )
   {//delay(1000);
 motorCoast() ;
 //Serial.println("s");
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
 
 analogWrite(enableA_l1, 230); 
 analogWrite(enableA_l2, 230);
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

