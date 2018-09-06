
#include <Wire.h>


unsigned long x = 0;
unsigned long y = 0;
char c;
//#include <PID_v1.h>


//double Kp=0, Ki=10, Kd=0;
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int i=0;


int LED = 4;
 
//int encoder0PinA = 5;//7
int encoder0PinA = 5;               // Motor 5 BIN_1 AXIS
//int encoder0PinB = 6;//8
int encoder0PinB = 6;
//int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
//long pos0 = 0;

//int encoder1PinA = 7;//5
int encoder1PinA = 7;             // Motor 6 AIN_1 JOINT
//int encoder1PinB = 8;//6
int encoder1PinB = 8;
//int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
//long pos1 = 0;

long encoder1PosR = 0;
long encoder0PosR = 0;

int encoder0PinALastR = 0;
int encoder1PinALastR = 0;

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


int BIN_1 = 11;       // Motor 5  AXIS
int BIN_2 = 12;

int AIN_1 = 9;       // Motor 6  JOINT 
int AIN_2 = 10;



void setup() {

  pinMode(LED, OUTPUT);
  pinMode(AIN_1, OUTPUT);
  pinMode(AIN_2, OUTPUT);
  pinMode(BIN_1, OUTPUT);
  pinMode(BIN_2, OUTPUT);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
  
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  //y = Wire.read();    // receive byte as an integer
  x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
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

 //receiveEvent;
 Read1();
 Read2();
  
  //If value received is 0 blink LED for 200 ms
  if(c == 'a'){
      rotateVal7 = x*10;
      //Serial.print(x);
      if (x > 0) {
        digitalWrite(LED, HIGH);
      }
      //If value received is 3 blink LED for 400 ms
      else {
        digitalWrite(LED, LOW);
      }

  }
  
  if(c == 'b'){
      rotateVal8 = x;
    //  Serial.print(y);
       if (x > 0) {
        digitalWrite(LED, HIGH);
      }
      else {

        digitalWrite(LED, LOW);

      }

  }
  if(c == 'c'){
        digitalWrite(BIN_1, LOW);
        digitalWrite(BIN_2, LOW);
        digitalWrite(AIN_1, LOW);
        digitalWrite(AIN_2, LOW);
        x = 0;
        y = 0;
        
        encoder0PosR = 0;
        encoder1PosR = 0;
        rotateVal7 = 0;
        rotateVal8 = 0; 
        delay(400);      
    }
  


     
  int mSpeed1 = 110;                                  // 1st speed of the AXIS MOTOR & JOINT MOTOR
  int mSpeed2 = 150;
   
 if((encoder0PosR-rotateVal7)>-2 && (encoder0PosR-rotateVal7)<2){        // THUMB AXIS
  digitalWrite(BIN_1, LOW);
  digitalWrite(BIN_2, LOW);
 }else if((encoder0PosR-rotateVal7)<20 && (encoder0PosR-rotateVal7)>0){
  analogWrite(BIN_1, mSpeed1);
  digitalWrite(BIN_2, LOW);
 }else if((rotateVal7-encoder0PosR)<20 && (rotateVal7-encoder0PosR)>0){
  digitalWrite(BIN_1, LOW);
  analogWrite(BIN_2, mSpeed1);
 }else if(encoder0PosR < rotateVal7){
  digitalWrite(BIN_1, LOW);
  analogWrite(BIN_2, mSpeed2);
 }else if(encoder0PosR > rotateVal7){
  analogWrite(BIN_1, mSpeed2);
  digitalWrite(BIN_2, LOW);
 }
  
                                   // speed of the JOINT MOTOR
   
   if((encoder1PosR-rotateVal8)>-2 && (encoder1PosR-rotateVal8)<2){          // THUMB JOINT
    digitalWrite(AIN_1, LOW);
    digitalWrite(AIN_2, LOW);
   }else if((encoder1PosR-rotateVal8)<20 && (encoder1PosR-rotateVal8)>0){
    digitalWrite(AIN_1, LOW);
    analogWrite(AIN_2, mSpeed1);
   }else if((rotateVal8-encoder1PosR)<20 && (rotateVal8-encoder1PosR)>0){
    analogWrite(AIN_1, mSpeed1);
    digitalWrite(AIN_2, LOW);
   }else if(encoder1PosR < rotateVal8){
    analogWrite(AIN_1, mSpeed2);
    digitalWrite(AIN_2, LOW);
   }else if(encoder1PosR > rotateVal8){
    digitalWrite(AIN_1, LOW);
    analogWrite(AIN_2, mSpeed2);
   }
 



}
