/*
    * File        : touch sensor
    * Author      : bassem
    * Date        : 23/8/2017
*/
#define TOUCH_SENSOR 0 //the touch sensor is connected to D0
  
int led = 13; // pin for the LED
  
void setup() 
{
 
pinMode(led, OUTPUT);
pinMode(TOUCH_SENSOR, INPUT);
}
  
void loop() 
{
int sensorValue = digitalRead(TOUCH_SENSOR);
  if(sensorValue)
  {
  digitalWrite(led, HIGH); // turn LED on
  while(digitalRead(TOUCH_SENSOR) == HIGH);
  digitalWrite(led, LOW); // turn LED off
  }
} 
