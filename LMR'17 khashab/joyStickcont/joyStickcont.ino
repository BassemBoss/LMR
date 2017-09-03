int  yPin = A1;
int xPin = A0;
int x=0 ,y=0;
int xPosition = 0;
int yPosition = 0;
int x_axis = 0 ;
int y_axis = 0 ;  
void setup() {
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  
}

void loop() {
 
 

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
 
  
 switch(x){
  case 1 : x++;break;
  case -1 : x-- ;break;}

  switch(y){
  case 1 : y++;break;
  case -1 : y-- ;break;
 
 }
 Serial.println("X: ");
  //Serial.println(xPosition);
  Serial.println(x);
  Serial.println(" | Y: ");
  //Serial.println(yPosition); 
  Serial.println(y);
 delay(500); // add some delay between reads

   
}

