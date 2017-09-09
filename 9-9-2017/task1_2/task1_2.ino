#include <Servo.h>
#include <Wire.h>
Servo shoulderServo1;
Servo shoulderServo2;
Servo elbowServo;
Servo gripperServo;
Servo gripper;
  
//Motor A pins"left motors"
#define enableA_l1    4
#define enableA_l2    5
#define pinA1   23
#define pinA2   25
#define pinA3   27
#define pinA4   29

//Motor B pins"right motors"
#define enableB_R1   6
#define enableB_R2   3
#define pinB1   22
#define pinB2   24
#define pinB3   26
#define pinB4   28




//Declaring some global variables
int gyro_x, gyro_y, gyro_z;
long gyro_x_cal, gyro_y_cal, gyro_z_cal;
boolean set_gyro_angles;

long acc_x, acc_y, acc_z, acc_total_vector;
float angle_roll_acc, angle_pitch_acc;

float angle_pitch, angle_roll;
int angle_pitch_buffer, angle_roll_buffer;
float angle_pitch_output, angle_roll_output;

long loop_timer;
int temp; 

int beta1,beta2;
int beta3;
int beta11;
int x = 70;
int y = 90;
int x_axis = 0 ;
int y_axis = 0 ;
int button = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 

     shoulderServo1.attach(7);
  shoulderServo2.attach(12); 
  elbowServo.attach(13);
  gripperServo.attach(3) ; 
  gripper.attach(5);
  

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
  
  
  Wire.begin();                                                        //Start I2C as master

  setup_mpu_6050_registers();                                          //Setup the registers of the MPU-6050 
 
  for (int cal_int = 0; cal_int < 1000 ; cal_int ++){                  //Read the raw acc and gyro data from the MPU-6050 for 1000 times
    read_mpu_6050_data();                                             
    gyro_x_cal += gyro_x;                                              //Add the gyro x offset to the gyro_x_cal variable
    gyro_y_cal += gyro_y;                                              //Add the gyro y offset to the gyro_y_cal variable
    gyro_z_cal += gyro_z;                                              //Add the gyro z offset to the gyro_z_cal variable
    delay(3);  
      }

  // divide by 1000 to get avarage offset
  gyro_x_cal /= 1000;                                                 
  gyro_y_cal /= 1000;                                                 
  gyro_z_cal /= 1000; 
                                                  
  loop_timer = micros(); 
         
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
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
  else if (data == 'f' )
  {//delay(1000);
  x_axis = 1 ;
  x = x + x_axis;
   if (x <= 160){
      arm ();
    }
  //Serial.println("r");
  }
   else if (data == 'b' )
  {//delay(1000);
  x_axis = -1 ;
  x = x + x_axis;
   if (x <= 160){
      arm ();
    }
  //Serial.println("r");
  }
   else if (data == 'l' )
  {//delay(1000);
  y_axis = -1 ; 
  y = y + y_axis;
   if (x <= 160){
      arm ();
    }
  //Serial.println("r");
  }
   else if (data == 'r' )
  {//delay(1000);
  y_axis = 1 ;
  y = y + y_axis;
   if (x <= 160){
      arm ();
    }
  //Serial.println("r");
  }
  }
}
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
 mpu_6050 ();
 analogWrite(enableA_l1, 230); 
 analogWrite(enableA_l2, 230);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
  shoulderServo1.write(beta1);
elbowServo.write(beta3);
shoulderServo2.write(beta11);
gripperServo.write(angle_pitch_output);
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
  mpu_6050 ();
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
   shoulderServo1.write(beta1);
elbowServo.write(beta3);
shoulderServo2.write(beta11);
gripperServo.write(angle_pitch_output);
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
 mpu_6050 ();
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
   shoulderServo1.write(beta1);
elbowServo.write(beta3);
shoulderServo2.write(beta11);
 gripperServo.write(angle_pitch_output);
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
  mpu_6050 ();
 analogWrite(enableA_l1, 255); 
 analogWrite(enableA_l2, 255);
 analogWrite(enableB_R1, 255);
 analogWrite(enableB_R2, 255);
   shoulderServo1.write(beta1);
elbowServo.write(beta3);
shoulderServo2.write(beta11);
  gripperServo.write(angle_pitch_output);
}
void read_mpu_6050_data(){                                             //Subroutine for reading the raw gyro and accelerometer data
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x3B);                                                    //Send the requested starting register
  Wire.endTransmission();                                              //End the transmission
  Wire.requestFrom(0x68,14);                                           //Request 14 bytes from the MPU-6050
  while(Wire.available() < 14);                                        //Wait until all the bytes are received
  acc_x = Wire.read()<<8|Wire.read();                                  
  acc_y = Wire.read()<<8|Wire.read();                                  
  acc_z = Wire.read()<<8|Wire.read();                                  
  temp = Wire.read()<<8|Wire.read();                                   
  gyro_x = Wire.read()<<8|Wire.read();                                 
  gyro_y = Wire.read()<<8|Wire.read();                                 
  gyro_z = Wire.read()<<8|Wire.read();                                 
}
void setup_mpu_6050_registers(){
  //Activate the MPU-6050
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x6B);                                                    //Send the requested starting register
  Wire.write(0x00);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
  //Configure the accelerometer (+/-8g)
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x1C);                                                    //Send the requested starting register
  Wire.write(0x10);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
  //Configure the gyro (500dps full scale)
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x1B);                                                    //Send the requested starting register
  Wire.write(0x08);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
}
void arm (){
  
    beta1 = map(x, -30, 140, 50, 180); 
    beta11 = map(x, -30, 140, 170, 50);

beta2 = map(x, -30, 140, 170, 40);
shoulderServo1.write(beta1);
 beta3 = map(y, 0, 140, 40, 130);
elbowServo.write(beta3);
shoulderServo2.write(beta11);
mpu_6050 ();
gripperServo.write(angle_pitch_output);
//gripper.write(y);
  
}
void mpu_6050 (){
  read_mpu_6050_data();   
 //Subtract the offset values from the raw gyro values
  gyro_x -= gyro_x_cal;                                                
  gyro_y -= gyro_y_cal;                                                
  gyro_z -= gyro_z_cal;                                                
         
  //Gyro angle calculations . Note 0.0000611 = 1 / (250Hz x 65.5)
  angle_pitch += gyro_y * 0.0000611;                                   //Calculate the traveled pitch angle and add this to the angle_pitch variable
  angle_roll += gyro_x * 0.0000611;                                    //Calculate the traveled roll angle and add this to the angle_roll variable
  //0.000001066 = 0.0000611 * (3.142(PI) / 180degr) The Arduino sin function is in radians
  angle_pitch += angle_roll * sin(gyro_z * 0.000001066);               //If the IMU has yawed transfer the roll angle to the pitch angel
  angle_roll -= angle_pitch * sin(gyro_z * 0.000001066);               //If the IMU has yawed transfer the pitch angle to the roll angel
  
  //Accelerometer angle calculations
  acc_total_vector = sqrt((acc_x*acc_x)+(acc_y*acc_y)+(acc_z*acc_z));  //Calculate the total accelerometer vector
  //57.296 = 1 / (3.142 / 180) The Arduino asin function is in radians
  angle_pitch_acc = asin((float)acc_x/acc_total_vector)* 57.296;       //Calculate the pitch angle
  angle_roll_acc = asin((float)acc_y/acc_total_vector)* -57.296;       //Calculate the roll angle
  
  angle_pitch_acc -= 0.0;                                              //Accelerometer calibration value for pitch
  angle_roll_acc -= 0.0;                                               //Accelerometer calibration value for roll

  if(set_gyro_angles){                                                 //If the IMU is already started
    angle_pitch = angle_pitch * 0.9996 + angle_pitch_acc * 0.0004;     //Correct the drift of the gyro pitch angle with the accelerometer pitch angle
    angle_roll = angle_roll * 0.9996 + angle_roll_acc * 0.0004;        //Correct the drift of the gyro roll angle with the accelerometer roll angle
  }
  else{                                                                //At first start
    angle_pitch = angle_pitch_acc;                                     //Set the gyro pitch angle equal to the accelerometer pitch angle 
    angle_roll = angle_roll_acc;                                       //Set the gyro roll angle equal to the accelerometer roll angle 
    set_gyro_angles = true;                                            //Set the IMU started flag
  }
  
  //To dampen the pitch and roll angles a complementary filter is used
  angle_pitch_output = angle_pitch_output * 0.9 + angle_pitch * 0.1;   //Take 90% of the output pitch value and add 10% of the raw pitch value
  angle_roll_output = angle_roll_output * 0.9 + angle_roll * 0.1;      //Take 90% of the output roll value and add 10% of the raw roll value
  // Serial.println(angle_pitch_output);

 while(micros() - loop_timer < 4000);                                 //Wait until the loop_timer reaches 4000us (250Hz) before starting the next loop
 loop_timer = micros();//Reset the loop timer

}

