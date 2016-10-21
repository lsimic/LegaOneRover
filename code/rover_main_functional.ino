/* DISCLAMER
This code was written by LegaOne rover development team, precisely members Robert Marko and Luka Simic.
In case that this code works, above stated must be given full credit.
In case the code does not work, above stated must not be associated with the following code.
LegaOne development team is not responsible for any damage that may occour while using this code.
USE AT YOUR OWN RISK 
 */

/*#include <NewPing.h>

#define TRIGGER_PIN_1  22  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_1     23  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define TRIGGER_PIN_2  24  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     25  // Arduino pin tied to echo pin on the ultrasonic sensor.

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
*/
//Start Motor pin defining
//on the shield, front motors
int Motor_FR_Direction = 12;    
int Motor_FR_Brake = 9;  
int Motor_FR_Speed = 3;
int Motor_FL_Direction = 13;    
int Motor_FL_Brake = 8;
int Motor_FL_Speed = 11;
//on the bridge, rear motors, FML
int Motor_RR_Forward = 26;
int Motor_RR_Backwards = 27;
int Motor_RL_Forward = 28;
int Motor_RL_Backwards = 29;
//End Motor pin defining
//Start Camera pin defining
/*int CameraA = 12;
int CameraB = 13;*/
//End Camera pin defining

//Serial define
  String FW = "Front_start";
  String BK = "Back_start";
  String LT = "Left_start";
  String RT = "Right_start";
  String Stop = "STOP";
  String CameraLeft = "Left_camera";
  String CameraRight = "Right_camera";

void setup() {
  Serial.begin(19200);
  pinMode(Motor_FR_Direction, OUTPUT);
  pinMode(Motor_FR_Brake, OUTPUT);
  pinMode(Motor_FR_Speed, OUTPUT);
  pinMode(Motor_FL_Direction, OUTPUT);
  pinMode(Motor_FL_Brake, OUTPUT);
  pinMode(Motor_FL_Speed, OUTPUT);
  pinMode(Motor_RR_Forward, OUTPUT);
  pinMode(Motor_RR_Backwards, OUTPUT);
  pinMode(Motor_RL_Forward, OUTPUT);
  pinMode(Motor_RL_Backwards, OUTPUT);
 /* pinMode(CameraA,OUTPUT);
  pinMode(CameraB,OUTPUT);*/
}

void loop() 
{  
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
//  unsigned int distance_front = sonar_1.ping_cm(); // Send ping, get distance in centimeters (cm).
//  unsigned int distance_back = sonar_2.ping_cm(); // Send ping, get distance in centimeters (cm).
  

 //the following code is simple and self-explainatory
  
  if (Serial.available())
  {//Checking for serial port("Basically worthless") 
	  String input = "";
    input = Serial.readStringUntil(10);
		if(input == FW) 
		{
			digitalWrite(Motor_FL_Direction, HIGH);
			digitalWrite(Motor_FL_Brake, LOW);
      digitalWrite(Motor_FL_Speed, HIGH);
      
			digitalWrite(Motor_FR_Direction, HIGH);
      digitalWrite(Motor_FR_Brake, LOW);
      digitalWrite(Motor_FR_Speed, HIGH);
      
			digitalWrite(Motor_RR_Backwards, LOW);
			digitalWrite(Motor_RL_Backwards, LOW);
      digitalWrite(Motor_RL_Forward, HIGH);
      digitalWrite(Motor_RR_Forward, HIGH);
		}
		else if(input == BK) 
		{
      digitalWrite(Motor_FL_Direction, LOW);
      digitalWrite(Motor_FL_Brake, LOW);
      digitalWrite(Motor_FL_Speed, HIGH);
      
      digitalWrite(Motor_FR_Direction, LOW);
      digitalWrite(Motor_FR_Brake, LOW);
      digitalWrite(Motor_FR_Speed, HIGH);
      
			digitalWrite(Motor_RL_Forward, LOW);
			digitalWrite(Motor_RR_Forward, LOW);
			digitalWrite(Motor_RR_Backwards, HIGH);
			digitalWrite(Motor_RL_Backwards, HIGH);
		}
		else if(input == LT) 
		{
      digitalWrite(Motor_FL_Direction, LOW);
      digitalWrite(Motor_FL_Brake, LOW);
      digitalWrite(Motor_FL_Speed, HIGH);
      
      digitalWrite(Motor_FR_Direction, HIGH);
      digitalWrite(Motor_FR_Brake, LOW);
      digitalWrite(Motor_FR_Speed, HIGH);

      digitalWrite(Motor_RL_Forward, LOW);
      digitalWrite(Motor_RR_Forward, HIGH);
      digitalWrite(Motor_RR_Backwards, LOW);
      digitalWrite(Motor_RL_Backwards, HIGH);
		}
		else if(input == RT) 
		{
      digitalWrite(Motor_FL_Direction, HIGH);
      digitalWrite(Motor_FL_Brake, LOW);
      digitalWrite(Motor_FL_Speed, HIGH);
      
      digitalWrite(Motor_FR_Direction, LOW);
      digitalWrite(Motor_FR_Brake, LOW);
      digitalWrite(Motor_FR_Speed, HIGH);
      
      digitalWrite(Motor_RL_Forward, HIGH);
      digitalWrite(Motor_RR_Forward, LOW);
      digitalWrite(Motor_RR_Backwards, HIGH);
      digitalWrite(Motor_RL_Backwards, LOW);	
		}
		else if(input == Stop)
		{
      digitalWrite(Motor_FL_Direction, LOW);
      digitalWrite(Motor_FL_Brake, HIGH);
      digitalWrite(Motor_FL_Speed, LOW);
      
      digitalWrite(Motor_FR_Direction, LOW);
      digitalWrite(Motor_FR_Brake, HIGH);
      digitalWrite(Motor_FR_Speed, LOW);
      
			digitalWrite(Motor_RL_Forward, LOW);
			digitalWrite(Motor_RR_Forward, LOW);
			digitalWrite(Motor_RR_Backwards, LOW);
			digitalWrite(Motor_RL_Backwards, LOW);		
		}

    
    
	/*
	this code should be added when the motors for camera controll are added. 
	the buttons and code already exists in the website code, and should only be enabled here. 
	*/
	  /*
	
	while(input == CameraLeft)
		{
			digitalWrite(CameraA, HIGH);
      digitalWrite(CameraB, LOW);
		}
		while(input == CameraRight)
		{
      digitalWrite(CameraA, LOW);
      digitalWrite(CameraB, HIGH);			
		}
		*/

	}
  }

