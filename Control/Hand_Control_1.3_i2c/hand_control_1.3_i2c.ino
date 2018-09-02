
#include <Wire.h>

unsigned long x = 0;
//#include <PID_v1.h>
int sensorPin1 = A1;    // Point finger
int sensorPin2 = A2;    // Middle finger 
int sensorPin3 = A0;    // Ring finger

//double Kp=0, Ki=10, Kd=0;
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int i=0;
int rotateVal = 40;

int encoder0PinA = 19;
int encoder0PinB = 18;
//int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
//long pos0 = 0;

int encoder1PinA = 21;
int encoder1PinB = 20;
//int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
//long pos1 = 0;

long encoder1PosR = 0;
long encoder0PosR = 0;

int encoder0PinALastR = 0;
int encoder1PinALastR = 0;

int y;
int r;
unsigned long serialData;
int inbyte; 
int digitalState;
int pinNumber;
int analogRate;

int sensorVal1;
int sensorVal2;
int sensorVal3;

int rotateVal1 = 120;
int rotateVal2 = 120;
int rotateVal3 = 120;
int rotateVal4;
int rotateVal5;

int sensorVal7;
int sensorVal8;
int sensorVal9;

int rotateVal7;
int rotateVal8;
int rotateVal9;
int mot1p = 7;       // Motor 1  POINT  OPENING  sensor 1
int mot1m = 6;       //                 CLOSING

int mot2p = 13;      // Motor 2 MIDDLE  OPENING  sensor 2
int mot2m = 12;      //                 CLOSING

int mot3p = 10;      // Motor 3  RING   OPENING  sensor 3
int mot3m = 11;      //                 CLOSING

int mot4p = 5;       // Motor 4  PINKY  OPENING
int mot4m = 4;       //                 CLOSING

int BIN_1 = 9;       // Motor 5  AXIS
int BIN_2 = 8;

int AIN_1 = 3;       // Motor 6  JOINT 
int AIN_2 = 2;

int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int sensorValue3 = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

//  Setpoint = 75;
//  myPID.SetMode(AUTOMATIC);
//  myPID.SetTuning(Kp, Ki, Kd);
 
  
  pinMode(mot1p, OUTPUT);
  pinMode(mot1m, OUTPUT);
  pinMode(mot2p, OUTPUT);
  pinMode(mot2m, OUTPUT);
  pinMode(mot3p, OUTPUT);
  pinMode(mot3m, OUTPUT);
  pinMode(mot4p, OUTPUT);
  pinMode(mot4m, OUTPUT);
  
  pinMode(AIN_1, OUTPUT);
  pinMode(AIN_2, OUTPUT);
  pinMode(BIN_1, OUTPUT);
  pinMode(BIN_2, OUTPUT);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
}

void Read1(){
 // encoderPosR = encoderPos;
  
  n0 = digitalRead(encoder0PinA);
  if ((encoder0PinALastR == LOW) && (n0 == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0PosR--;
    } else {
      encoder0PosR++;
    }
    //pos0 = encoder0PosR;
    Serial.print (encoder0PosR);
    Serial.print ("\n");
    //encoder0Pos = encoder0PosR;
  }
  encoder0PinALastR = n0;
 }


void Read2(){
 // encoderPosR = encoderPos;
  
  n1 = digitalRead(encoder1PinA);
  if ((encoder1PinALastR == LOW) && (n1 == HIGH)) {
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1PosR--;
    } else {
      encoder1PosR++;
    }
   // pos1 = encoder1PosR;
    Serial.print (encoder1PosR);
    Serial.print ("\n");
    //encoder1Pos = encoder1PosR;
  }
  encoder1PinALastR = n1;
 }


void loop() {
// Read1();
// Read2();
 sensorValue1 = analogRead(sensorPin1);
 sensorValue2 = analogRead(sensorPin2);
 sensorValue3 = analogRead(sensorPin3);


     if(sensorValue1<20 && sensorValue1>330){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);      
     }else if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
     }else if (rotateVal1>sensorValue1){
      digitalWrite(mot1p, HIGH); //OPENS INDEX finger
      digitalWrite(mot1m, LOW);              
     }else if(rotateVal1<sensorValue1){
      digitalWrite(mot1p, LOW); //CLOSES INDEX finger
      digitalWrite(mot1m, HIGH);  
     }
     
     if(sensorValue2<20 && sensorValue2>330){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);      
     }else if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
     }else if (rotateVal2>sensorValue2){
      digitalWrite(mot2p, HIGH); //OPENS MIDDLE finger
      digitalWrite(mot2m, LOW);              
     }else if(rotateVal2<sensorValue2){
      digitalWrite(mot2p, LOW); //CLOSES MIDDLE finger
      digitalWrite(mot2m, HIGH);  
     } 
     
     if(sensorValue3<20 && sensorValue3>330){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);  
     }else if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);
     }else if (rotateVal3>sensorValue3){
      digitalWrite(mot3p, HIGH); //OPENS RING finger
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, HIGH); //OPENS PINKY
      digitalWrite(mot4m, LOW);                  
     }else if(rotateVal3<sensorValue3){
      digitalWrite(mot3p, LOW); //CLOSES RING finger
      digitalWrite(mot3m, HIGH);
      digitalWrite(mot4p, LOW); //CLOSES PINKY
      digitalWrite(mot4m, HIGH);  
     }else{
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);      
     }
     
//int mSpeed1 = 160;                                  // speed of the AXIS MOTOR
//
// if((encoder0PosR-rotateVal7)>-2 && (encoder0PosR-rotateVal7)<2){              // THUMB AXIS
//  digitalWrite(BIN_1, LOW);
//  digitalWrite(BIN_2, LOW);
// }else if((encoder0PosR-rotateVal7)<20 && (encoder0PosR-rotateVal7)>0){
//  analogWrite(BIN_1, mSpeed1);
//  digitalWrite(BIN_2, LOW);
// }else if((rotateVal7-encoder0PosR)<20 && (rotateVal7-encoder0PosR)>0){
//  digitalWrite(BIN_1, LOW);
//  analogWrite(BIN_2, mSpeed1);
// }else if(encoder0PosR < rotateVal7){
//  digitalWrite(BIN_1, LOW);
//  analogWrite(BIN_2, mSpeed1);
// }else if(encoder0PosR > rotateVal7){
//  analogWrite(BIN_1, mSpeed1);
//  digitalWrite(BIN_2, LOW);
// }
//
// int mSpeed2 = 160;                                 // speed of the JOINT MOTOR
// 
// if((encoder1PosR-rotateVal8)>-2 && (encoder1PosR-rotateVal8)<2){              // THUMB JOINT
//  digitalWrite(AIN_1, LOW);
//  digitalWrite(AIN_2, LOW);
// }else if((encoder1PosR-rotateVal8)<20 && (encoder1PosR-rotateVal8)>0){
//  digitalWrite(AIN_1, LOW);
//  analogWrite(AIN_2, mSpeed2);
// }else if((rotateVal8-encoder1PosR)<20 && (rotateVal8-encoder1PosR)>0){
//  analogWrite(AIN_1, mSpeed2);
//  digitalWrite(AIN_2, LOW);
// }else if(encoder1PosR < rotateVal8){
//  analogWrite(AIN_1, mSpeed2);
//  digitalWrite(AIN_2, LOW);
// }else if(encoder1PosR > rotateVal8){
//  digitalWrite(AIN_1, LOW);
//  analogWrite(AIN_2, mSpeed2);
// }
 
 if (Serial.available() > 0){
  serialRead();
  switch(serialData)
   {
    case 1:
      { serialRead();
        rotateVal1 = serialData;
        Serial.print("Value of sensor:  ");
        Serial.print(sensorValue1);
        Serial.print("\n");
        Serial.print("Value of rotation Point finger:  ");
        Serial.print(rotateVal1);
        Serial.print("\n");
        break;
      }
    case 2:
      {
        serialRead();
        rotateVal2 = serialData;
        Serial.print("Value of sensor:  ");
        Serial.print(sensorValue2);
        Serial.print("\n");
        Serial.print("Value of rotation Middle finger:  ");
        Serial.print(rotateVal2);
        Serial.print("\n");
        break;
      }
    case 3:
      {
        serialRead();
        rotateVal3 = serialData;
        Serial.print("Value of sensor:  ");
        Serial.print(sensorValue3);
        Serial.print("\n");
        Serial.print("Value of rotation Ring finger:  ");
        Serial.print(rotateVal3);
        Serial.print("\n");
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
        digitalWrite(AIN_1, LOW);
        digitalWrite(AIN_2, LOW);
        digitalWrite(BIN_1, LOW);
        digitalWrite(BIN_2, LOW);
        digitalWrite(mot1p, LOW);
        digitalWrite(mot1m, LOW);
        digitalWrite(mot2p, LOW);
        digitalWrite(mot2m, LOW);
        digitalWrite(mot3p, LOW);
        digitalWrite(mot3m, LOW);
        digitalWrite(mot4p, LOW);
        digitalWrite(mot4m, LOW);
        
 
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("c");          // sends x 
        Wire.endTransmission(); 
        rotateVal1 = sensorValue1;
        rotateVal2 = sensorValue2;
        rotateVal3 = sensorValue3;
        delay(1000);               
        Serial.print("Command of STOP");
        Serial.print("\n");
        break;                         
      }      
    case 7:
      {
        Serial.print("S1: ");
        Serial.print(sensorValue1 );
        Serial.print("\t");    
      
        Serial.print("  S2: ");
        Serial.print(sensorValue2);
        Serial.print("\t");
      
        Serial.print("S3: "); 
        Serial.print(sensorValue3);
        Serial.print("\t"); 

        Serial.print("  inVal1: "); 
        Serial.print(rotateVal1);
        Serial.print("\t");
        
        Serial.print("inVal2: "); 
        Serial.print(rotateVal2);
        Serial.print("\t");

        Serial.print("inVal3: "); 
        Serial.print(rotateVal3);
        Serial.print("\n");

        Serial.print("Value of pos Axis:  ");
        Serial.print(encoder0PosR);
        Serial.print("\t");
        Serial.print("\t");
        Serial.print("Value of pos JOINT:  ");
        Serial.print(encoder1PosR);
        Serial.print("\n");
        break;
      } 
    case 8:
      {
        digitalWrite(AIN_1, LOW);
        digitalWrite(AIN_2, LOW);
        digitalWrite(BIN_1, LOW);
        digitalWrite(BIN_2, LOW);
        delay(100);
        encoder0PosR = 0;
        encoder1PosR = 0;
        rotateVal7 = 0;
        rotateVal8 = 0;           
        break;
      }     
   }     
 }
}


long getSerial()
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
