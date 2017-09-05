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
#define pinB1   7  // reverse 3
#define pinB2   8  // forword 3
#define pinB3   12  // revesr 4
#define pinB4   13  // forword 4

void setup() {
 Serial.begin(9600);
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
}
void loop() {
  // put your main code here, to run repeatedly:
 // if (Serial.available() > 0) // in serial arduino 
 while (Serial.available()) // in bluetooth 
 {
  char data = Serial.read();
  if (data == 'C')
  {
   task3() ;
   Serial.println("task 3 on ");
  }
 }
}
void task3 ()
{ 
  volatile char rounds =0 ,i , box1color=0 , box2color=0 ,  box3color=0 ,a , arm_base ,z , x ,d ,  r , l , c , box2grasped , box1grasped ;
  short int Check_point[8]={0,0,0,0,0,0,0,0} ; // 0 for not enter in that check point , 1 enter in that check_point , 2 grasped a box in that check_point
  volatile  char arm_objected=0 ;


  
  //arm_initial_dimension();  // arm initial
  Serial.println("set arm initial ");


  
  // color selection boxs :
  for (i=0;i<3;i++)
  {
  // if (Serial.available() > 0)  // in serial arduino 
  if (Serial.available()) // in bluetooth 
 {
  Serial.print ("enter color of box");
  Serial.println (i+1);
  Serial.println("1 for red \n2 for green \n3 for  blue \n\n\n");
  // in bluetooth :
  // 11 redbox1 , 21 greenbox1 , 31 bluebox1
  // 12 redbox2 , 22 greenbox2 , 32 bluebox2
  // 13 redbox3 , 23 greenbox3 , 33 bluebox3
  if (i==0)
  box1color = Serial.read();
  else if (i==1)
  box2color = Serial.read();
  else if (i==2)
  box3color = Serial.read();
 }
  } // end color selection boxs

  lineloop :
  // char x = start_line_check();  // start line check with line follower array 
  slow_Forward() ;  
  x = Serial.read();  // start line check 
  if (x==1)
   {
    while (d<30) // random forword to go distance after start line
    { 
    Forward();
    }
    //start_task3
    rounds=1; 
    for (i=0;i<8;i++)
    {
    cross_line_IRSensor_check :
    Forward();
    // char f = cross_line_IRSensor_check(); // return 1 if found cross line
    //char y = Ultrasonic_sensor_check(); // return The distance between robot and an box
    Serial.println("are you found cross line ");
    char f = Serial.read() ; 
    Serial.println("enter The distance between robot and an box ");
    char y = Serial.read() ; 
    if (f==1)
    {
     i++;
     Serial.print("found cross line no    ");
     Serial.println(i);
     if (i==0 ||i== 2 ||i== 4 ||i== 6 ||i== 8)
     {
      goto cross_line_IRSensor_check ; 
     }
     else if (i==1 ||i== 3 ||i== 5 ||i== 7)
     {
      if (Check_point[i]==0)
      {
        Check_point[i]=1;
        Turn_Right_with_linefollow :
        //   r = Turn_Right_with_linefollow(); // return 1 if line follow correct , return  0 if line follow is not correct 
        if (r == 1)
        {
          a = 0;
          goto gripper_compare ;    
        }
        else if (r == 0)
        {
          goto Turn_Right_with_linefollow ;
        }
      }
      else if ((a - i) == 0)
      {
        if ( i < 6 )
        {
         goto Turn_Right_with_linefollow ;
        }
        else if ( i == 6 || i>6 )
        {
         Turn_left_with_linefollow :
         //  l = Turn_left_with_linefollow(); // return 1 if line follow correct , return  0 if line follow is not correct 
         if (l == 1)
         {
          goto gripper_compare ;  
         }
         else if (l == 0)
         {
          goto Turn_left_with_linefollow ;
         }
         }
      }
      else if (a - i != 0)
      {
      goto cross_line_IRSensor_check ; 
      }
      
     }
     if ( y<=10 ) // our box here
     {
       motorCoast();
       //check color of box
       // c = Arm_reading_color_mode(); // 1 for red \n2 for green \n3 for  blue
      // in bluetooth :
      // 11 redbox1 , 21 greenbox1 , 31 bluebox1
      // 12 redbox2 , 22 greenbox2 , 32 bluebox2
      // 13 redbox3 , 23 greenbox3 , 33 bluebox3
       if (box1color==c)
       {
        box1grasped = 1 ;
       z = 1 ;
       call_back :
       //Arm_grasping();
       if (arm_base == 0)
       {
        arm_base = z ;
        //Arm_base_interaction();
        Check_point[i]=2;
        Arm_initial_Dimension :
        //Arm_initial_Dimension();
        Motor_Rotating :
        //Motor_Rotating();
        a = x ; 
        x --;
        gripper_compare :
        if ( box1grasped ==1 && box2grasped == 1 )
        {
          if ( arm_base == 1)
          {
            if ( i == 6)
            {
              //turn_left_with_adjustable_left_IR_Sensor();
              forward_with_adjustable_left_IR_Sensor :
              //forward_with_adjustable_left_IR_Sensor();   
              //char y = Ultrasonic_sensor_check(); // return The distance between robot and an box
              Serial.println("enter The distance between robot and an box ");
              y = Serial.read() ; 
              if (y <= 10)
              {
                stop_and_place :
                motorCoast();
                if (arm_objected == 1)
                {
                  arm_release :
                  //arm_release();
                  arm_objected = 0;
                }
                else if (arm_objected != 1)
                {
                  //arm_grasped_from_base();
                  //Arm_initial_Dimension();
                  goto arm_release;
                }
              }
              else if (y > 10)
              {
                 goto forward_with_adjustable_left_IR_Sensor ;
              }
            }
            else if (i == 8)
            {
              //turn_right_with_adjustable_left_IR_Sensor();
              goto forward_with_adjustable_left_IR_Sensor ;
              
            }
          }
          else if ( arm_base != 1 )
          {
            if ( i == 6)
            {
              //turn_left_with_adjustable_right_IR_Sensor();
              forward_with_adjustable_right_IR_Sensor :
              //forward_with_adjustable_right_IR_Sensor();              
              //char y = Ultrasonic_sensor_check(); // return The distance between robot and an box
              Serial.println("enter The distance between robot and an box ");
              y = Serial.read() ; 
              if (y <= 10)
              {
                goto stop_and_place ; 
              }
              else if (y > 10)
              {
                 goto forward_with_adjustable_left_IR_Sensor ;
              }
            }
            else if (i == 8)
            {
              //turn_right_with_adjustable_right_IR_Sensor();
              goto forward_with_adjustable_right_IR_Sensor  ;
            }
          }
        }
        else  if ( box1grasped !=1 && box2grasped != 1 )
        {
          goto cross_line_IRSensor_check ;
        }
       }
       else if (arm_base != 0)
       {
        arm_objected = 1 ;
        goto Arm_initial_Dimension ;
       }
       }
       else if (box2color==c)
       {
        box2grasped = 1 ;
       if (arm_base == 0)
        {
        z = 2 ;
        goto call_back ; 
        }
        else if (arm_base != 0)
        {
         goto call_back ; 
        }
        }
        else if (c!=box2color && c!=box1color )
        {
          goto Motor_Rotating ;
        }
     }
     else if ( y>10 ) 
     {
      goto cross_line_IRSensor_check ; 
     }
    }
    else if (f==0)
    {
      goto cross_line_IRSensor_check ; 
    }
    
   
    
    }
   }
  else if (x==0)
  {
  goto lineloop ; 
  }
}
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

void slow_Forward()
{
 digitalWrite(pinA1, 0);  // reverse 1
 digitalWrite(pinA2, 1);  // forword 1
 digitalWrite(pinA3, 0);  // reverse 2
 digitalWrite(pinA4, 1);  // forword 2 
 digitalWrite(pinB1, 0);  // reverse 1
 digitalWrite(pinB2, 1);
 digitalWrite(pinB3, 0);
 digitalWrite(pinB4, 1);
 
 analogWrite(enableA_l1, 128); 
 analogWrite(enableA_l2, 128);
 analogWrite(enableB_R1, 128);
 analogWrite(enableB_R2, 128);
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

