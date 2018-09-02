#include <Wire.h>

unsigned long x = 0;

//#include <PID_v1.h>


//double Kp=0, Ki=10, Kd=0;
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int i=0;


int ledPin = 9;
 
////int encoder0PinA = 5;//7
//int encoder0PinA = 5;               // Motor 5 BIN_1 AXIS
////int encoder0PinB = 6;//8
//int encoder0PinB = 6;
////int encoder0Pos = 0;
//int encoder0PinALast = LOW;
//int n0 = LOW;
////long pos0 = 0;
//
////int encoder1PinA = 7;//5
//int encoder1PinA = 7;             // Motor 6 AIN_1 JOINT
////int encoder1PinB = 8;//6
//int encoder1PinB = 8;
////int encoder1Pos = 0;
//int encoder1PinALast = LOW;
//int n1 = LOW;
////long pos1 = 0;
//
//long encoder1PosR = 0;
//long encoder0PosR = 0;
//
//int encoder0PinALastR = 0;
//int encoder1PinALastR = 0;

unsigned long serialData;
int inbyte; 
int digitalState;
int pinNumber;
int analogRate;

int rotateVal4;
int rotateVal5;

int sensorVal7;
int sensorVal8;
int sensorVal9;

int rotateVal7;
int rotateVal8;
int rotateVal9;
//
//
//int BIN_1 = 11;       // Motor 5  AXIS
//int BIN_2 = 12;
//
//int AIN_1 = 9;       // Motor 6  JOINT 
//int AIN_2 = 10;



void setup() {


  Wire.begin();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}



void loop() {
  
  
 
 if (Serial.available() > 0){
  serialRead();
  switch(serialData)
   {
    case 1:
      { 
       
        Serial.print("TEST \n");
        for(int i=0;i<=255;i++){
          analogWrite(ledPin, i);
          delay(10);
        }
        for(int i=255;i>=0;i--){
          analogWrite(ledPin, i);
          delay(10);
        }
        break;
      }
    case 2:
      {
        analogWrite(ledPin, 0);
        Serial.print("LED is OFF \n");
        break;
      }
    case 3:
      {
        analogWrite(ledPin, 255);
        Serial.print("LED is ON \n");
        break;
     }
    case 4:
      {         
        serialRead();
        rotateVal7 = serialData;
        x = serialData; 
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("a");
        Wire.write(x);              // sends x 
        Wire.endTransmission();    // stop transmitting
           
        Serial.print("Value of rotation thumb:  ");
        Serial.print(rotateVal7);
        Serial.print("\n");
        break;
      }
    case 5:
      { serialRead();
        rotateVal8 = serialData;
        x = serialData; 
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("b");
        Wire.write(x);              // sends x 
        Wire.endTransmission();    // stop transmitting
        
        Serial.print("Value of rotation joint:  ");
        Serial.print(rotateVal8);
        Serial.print("\n");
        break;
      }
     case 6: 
      {
//        digitalWrite(AIN_1, LOW);
//        digitalWrite(AIN_2, LOW);
//        digitalWrite(BIN_1, LOW);
//        digitalWrite(BIN_2, LOW);

        
        delay(1000);
//        rotateVal7 = encoder0PosR;
 //       rotateVal8 = encoder1PosR;
//        rotateVal1 = sensorValue1;
//        rotateVal2 = sensorValue2;
//        rotateVal3 = sensorValue3;               
        Serial.print("Command of STOP");
        Serial.print("\n");
        break;                         
      }      
    case 7:
      {


        Serial.print("Value of pos Axis:  ");
 //       Serial.print(encoder0PosR);
        Serial.print("\t");
        Serial.print("\t");
        Serial.print("Value of pos JOINT:  ");
 //       Serial.print(encoder1PosR);
        Serial.print("\n");
        break;
      } 
    case 8:
      {
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("c");          // sends x 
        Wire.endTransmission(); 
        rotateVal7 = 0;
        rotateVal8 = 0;           
        break;
      }     
   }     
 }
}





long serialRead()
{
  serialData = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read();
    if (inbyte > 0 && inbyte != '/')
    {
      serialData = serialData * 10 + inbyte - '0';  
      Serial.println(serialData);
    }
  }
  inbyte = 0; 
  return serialData;
}
