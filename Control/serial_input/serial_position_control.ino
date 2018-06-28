
int AIN_1 = 3;
int AIN_2 = 2;
int BIN_1 = 9;
int BIN_2 = 8;

int buttonState1 = 0;
int buttonState2 = 0;
  
int encoder0PinA = 19;
int encoder0PinB = 18;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
long pos0 = 0;

int encoder1PinA = 21;
int encoder1PinB = 20;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
long pos1 = 0;

int encoder1PosR = 0;
int encoder0PosR = 0;
unsigned long serialData;
int inbyte; 
int digitalState;
int pinNumber;
int analogRate;

int sensorVal1;
int sensorVal2;
int sensorVal3;

int rotateVal1;
int rotateVal2;
int rotateVal3;

int rotateVal4;

unsigned long time;

void setup() {
  // put your setup code here, to run once:
  pinMode(AIN_1, OUTPUT);
  pinMode(AIN_2, OUTPUT);
  pinMode(BIN_1, OUTPUT);
  pinMode(BIN_2, OUTPUT);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
//  pinMode(LED, OUTPUT);
  //Serial.println("start"); 
  Serial.begin (9600);
}



void forward(int x, int y) {
  digitalWrite(x, LOW);
  //digitalWrite(AIN_2, HIGH);
  analogWrite(y, 255);
}

void reverse(int x, int y) {
  //digitalWrite(AIN_1, HIGH);
  analogWrite(x, 255);
  digitalWrite(y, LOW);
}

void Stop(int x, int y) {
  digitalWrite(x, LOW);
  digitalWrite(y, LOW);
}
int encoder0PinALastR = 0;
int encoder1PinALastR =0;

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

void Read1(){
 // encoderPosR = encoderPos;
  
  n0 = digitalRead(encoder0PinA);
  if ((encoder0PinALastR == LOW) && (n0 == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0PosR--;
    } else {
      encoder0PosR++;
    }
    pos0 = encoder0PosR;
    Serial.print (encoder0PosR);
    Serial.print ("\n");
    encoder0Pos = encoder0PosR;
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
    pos1 = encoder1PosR;
    Serial.print (encoder1PosR);
    Serial.print ("\n");
    encoder1Pos = encoder1PosR;
  }
  encoder1PinALastR = n1;
  }

  

void loop() {
  
 Read1();
 Read2();
 if (Serial.available() > 0){
  serialRead();
  switch(serialData)
   {
    case 1:
      { serialRead();
        rotateVal1 = serialData;
       // Serial.print("Value of sensor:  ");
       // Serial.print(sensorValue1);
       // Serial.print("\n");
        Serial.print("Value of rotation thumb:  ");
        Serial.print(rotateVal1);
        Serial.print("\n");
        break;
      }
    case 2:
      { serialRead();
        rotateVal2 = serialData;
       // Serial.print("Value of sensor:  ");
       // Serial.print(sensorValue2);
       // Serial.print("\n");
        Serial.print("Value of rotation joint:  ");
        Serial.print(rotateVal2);
        Serial.print("\n");
        break;
      }
     case 3:
      {
       // Serial.print("Value of sensor:  ");
       // Serial.print(sensorValue2);
       // Serial.print("\n");
        Serial.print("Value of pos Axis:  ");
        Serial.print(pos0);
        Serial.print("\t");
        Serial.print("Value of pos JOINT:  ");
        Serial.print(pos1);
        Serial.print("\n");
        
        break;
      }
      
     case 5: 
      {
        digitalWrite(AIN_1, LOW);
        digitalWrite(AIN_2, LOW);
        digitalWrite(BIN_1, LOW);
        digitalWrite(BIN_2, LOW);
        delay(100);
        rotateVal1 = pos0;
        rotateVal2 = pos1;
        Serial.print("Command of STOP");
        Serial.print("\n");
        break;                         
      }
   }
 }


 
  
  
  
 if((pos0-rotateVal1)<20 && (pos0-rotateVal1)>0){
  analogWrite(BIN_1, 100);
  digitalWrite(BIN_2, LOW);
 }else if((rotateVal1-pos0)<20 && (rotateVal1-pos0)>0){
  digitalWrite(BIN_1, LOW);
  analogWrite(BIN_2, 100);
 }else if((pos0-rotateVal1)>-3 && (pos0-rotateVal1)<3){
  digitalWrite(BIN_1, LOW);
  digitalWrite(BIN_2, LOW);
 }else if(pos0 < rotateVal1){
  digitalWrite(BIN_1, LOW);
  digitalWrite(BIN_2, HIGH);
 }else if(pos0 > rotateVal1){
  digitalWrite(BIN_1, HIGH);
  digitalWrite(BIN_2, LOW);
 }

 if((pos1-rotateVal2)<50 && (pos1-rotateVal2)>20){
  digitalWrite(AIN_1, LOW);
  analogWrite(AIN_2, 128);
 }else if((rotateVal2-pos1)<50 && (rotateVal2-pos1)>20){
  analogWrite(AIN_1, 128);
  digitalWrite(AIN_2, LOW);
 }else if((pos1-rotateVal2)<20 && (pos1-rotateVal2)>0){
  digitalWrite(AIN_1, LOW);
  analogWrite(AIN_2, 80);
 }else if((rotateVal2-pos1)<20 && (rotateVal2-pos1)>0){
  analogWrite(AIN_1, 80);
  digitalWrite(AIN_2, LOW);
 }else if((pos1-rotateVal2)>-7 && (pos1-rotateVal2)<7){
  digitalWrite(AIN_1, LOW);
  digitalWrite(AIN_2, LOW);
 }else if(pos1 < rotateVal2){
  digitalWrite(AIN_1, HIGH);
  digitalWrite(AIN_2, LOW);
 }else if(pos1 > rotateVal2){
  digitalWrite(AIN_1, LOW);
  digitalWrite(AIN_2, HIGH);
 }
 
}
