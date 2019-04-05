//--- Library
#include <Servo.h>

//--- Pin Definitions
#define LEFTSERVOPIN  3    //The digital pin that the left servo is connected to
#define LEFTLIGHTSENSOR 0  //The analog pin the left light sensor is connected to
#define MIDDLELIGHTSENSOR 2
#define RIGHTLIGHTSENSOR 1 //The analog pin the right light sensor is connected to
#define LED 13           //The LED on the arduino

//--- Servo Setup
Servo leftServo;
 
//--- Speed Setupac
int rightSpeed = 50;
int leftSpeed = 50;

//--- Sensor Values
int leftLightSensorVal = 0;
int rightLightSensorVal = 0;
int middleLightSensorVal = 0;

//--- Delay Threshold
int delayParam = 10;  //Supported Times - 0 - 255 (0 to 25.5 Seconds) value * 100 milliseconds 

//--- The program setup
void setup()                  
{  
  Serial.begin(9600);                //Starts the serial port  
  robotSetup();                      //sets the state of all neccesarya
                                       //pins and adds servos to your sketch
}

//--- The main program code
void loop()                     
{  
  //--- Get information from the light sensor  
  leftLightSensorVal = analogRead(LEFTLIGHTSENSOR);  
  rightLightSensorVal = analogRead(RIGHTLIGHTSENSOR);    
  middleLightSensorVal = analogRead(MIDDLELIGHTSENSOR);

  
    digitalWrite(LED, HIGH); // turn LED ON    
    
    if(leftLightSensorVal>rightLightSensorVal && leftLightSensorVal>middleLightSensorVal)
    {      
      Serial.println("Left");
      leftServo.write(0);            
      delay(delayParam * 100);      
      goStop();    
    } 
    else if(rightLightSensorVal>leftLightSensorVal && rightLightSensorVal>middleLightSensorVal)
    {      
      Serial.println("Right");      
      leftServo.write(180);      
      delay(delayParam * 100);     
			goStop();    
    } 
    else 
    {      
      Serial.println("Middle");      
      leftServo.write(90);      
      delay(delayParam * 100);       
      goStop();    
    }  
   
     
}
