
int sensorPin1 = A1;    // Point finger
int sensorPin2 = A2;    // Middle finger 
int sensorPin3 = A0;    // Ring finger

int encoder0PinA = 15;  //0
int encoder0PinB = 14;  //1
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
long pos0 = 0;

int encoder1PinA = 15;
int encoder1PinB = 14;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
long pos1 = 0;
int encoderPinALastR = 0;

int encoderPosR = 0;
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
int rotateVal5;

int mot1p = 7;       // Motor 1  POINT  OPENING  sensor 1
int mot1m = 6;       //                 CLOSING

int mot2p = 13;      // Motor 2 MIDDLE  OPENING  sensor 2
int mot2m = 12;      //                 CLOSING

int mot3p = 10;      // Motor 3  RING   OPENING  sensor 3
int mot3m = 11;      //                 CLOSING

int mot4p = 5;       // Motor 4  PINKY  OPENING
int mot4m = 4;       //                 CLOSING

int mot5p = 9;       // Motor 5
int mot5m = 8;

int mot6p = 3;       // Motor 6
int mot6m = 2;

int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int sensorValue3 = 0;

void setup() {

  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(mot1p, OUTPUT);
  pinMode(mot1m, OUTPUT);
  pinMode(mot2p, OUTPUT);
  pinMode(mot2m, OUTPUT);
  pinMode(mot3p, OUTPUT);
  pinMode(mot3m, OUTPUT);
  pinMode(mot4p, OUTPUT);
  pinMode(mot4m, OUTPUT);
  pinMode(mot5p, OUTPUT);
  pinMode(mot5m, OUTPUT);
  pinMode(mot6p, OUTPUT);
  pinMode(mot6m, OUTPUT); 
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
}

void loop() {

   sensorValue1 = analogRead(sensorPin1);
   sensorValue2 = analogRead(sensorPin2);
   sensorValue3 = analogRead(sensorPin3);

   if(rotateVal1==0 && rotateVal2==0 && rotateVal3==0){                //when switched ON
     digitalWrite(mot1p, LOW);
     digitalWrite(mot1m, LOW);
     digitalWrite(mot2p, LOW);
     digitalWrite(mot2m, LOW);
     digitalWrite(mot3p, LOW);
     digitalWrite(mot3m, LOW);   
   }else if(rotateVal1!=0 && rotateVal2==0 && rotateVal3==0){          //when index finger set only
     if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
     }else if (rotateVal1>sensorValue1){
      digitalWrite(mot1p, HIGH); //OPENS INDEX finger
      digitalWrite(mot1m, LOW);              
     }else if(rotateVal1<sensorValue1){
      digitalWrite(mot1p, LOW); //CLOSES INDEX finger
      digitalWrite(mot1m, HIGH);  
     }
     digitalWrite(mot2p, LOW);
     digitalWrite(mot2m, LOW);
     digitalWrite(mot3p, LOW);
     digitalWrite(mot3m, LOW);  
   }else if(rotateVal1==0 && rotateVal2!=0 && rotateVal3==0){         //when middle findger set only 
     if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
     }else if (rotateVal2>sensorValue2){
      digitalWrite(mot2p, HIGH); //OPENS MIDDLE finger
      digitalWrite(mot2m, LOW);              
     }else if(rotateVal2<sensorValue2){
      digitalWrite(mot2p, LOW); //CLOSES MIDDLE finger
      digitalWrite(mot2m, HIGH);  
     }
     digitalWrite(mot1p, LOW);
     digitalWrite(mot1m, LOW);
     digitalWrite(mot3p, LOW);
     digitalWrite(mot3m, LOW); 
   }else if(rotateVal1==0 && rotateVal2==0 && rotateVal3!=0){         //when ring finger set only
     if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);
     }else if (rotateVal3>sensorValue3){
      digitalWrite(mot3p, HIGH); //OPENS RING finger
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, HIGH);
      digitalWrite(mot4m, LOW);                  
     }else if(rotateVal3<sensorValue3){
      digitalWrite(mot3p, LOW); //CLOSES RING finger
      digitalWrite(mot3m, HIGH);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, HIGH);  
     }
     digitalWrite(mot1p, LOW);
     digitalWrite(mot1m, LOW);
     digitalWrite(mot2p, LOW);
     digitalWrite(mot2m, LOW); 
   }else if(rotateVal1!=0 && rotateVal2!=0 && rotateVal3==0){         //when index and middle finger set only  
     if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
     }else if (rotateVal1>sensorValue1){
      digitalWrite(mot1p, HIGH); //OPENS INDEX finger
      digitalWrite(mot1m, LOW);              
     }else if(rotateVal1<sensorValue1){
      digitalWrite(mot1p, LOW); //CLOSES INDEX finger
      digitalWrite(mot1m, HIGH);  
     }
     if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
     }else if (rotateVal2>sensorValue2){
      digitalWrite(mot2p, HIGH); //OPENS MIDDLE finger
      digitalWrite(mot2m, LOW);              
     }else if(rotateVal2<sensorValue2){
      digitalWrite(mot2p, LOW); //CLOSES MIDDLE finger
      digitalWrite(mot2m, HIGH);  
     }
     digitalWrite(mot3p, LOW);
     digitalWrite(mot3m, LOW); 
   }else if(rotateVal1==0 && rotateVal2!=0 && rotateVal3!=0){
     if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
     }else if (rotateVal2>sensorValue2){
      digitalWrite(mot2p, HIGH); //OPENS MIDDLE finger
      digitalWrite(mot2m, LOW);              
     }else if(rotateVal2<sensorValue2){
      digitalWrite(mot2p, LOW); //CLOSES MIDDLE finger
      digitalWrite(mot2m, HIGH);  
     }
     if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);
     }else if (rotateVal3>sensorValue3){
      digitalWrite(mot3p, HIGH); //OPENS RING finger
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, HIGH);
      digitalWrite(mot4m, LOW);                  
     }else if(rotateVal3<sensorValue3){
      digitalWrite(mot3p, LOW); //CLOSES RING finger
      digitalWrite(mot3m, HIGH);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, HIGH);  
     }
     digitalWrite(mot1p, LOW);
     digitalWrite(mot1m, LOW);
   }else if(rotateVal1!=0 && rotateVal2==0 && rotateVal3!=0){  
     if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
     }else if (rotateVal1>sensorValue1){
      digitalWrite(mot1p, HIGH); //OPENS INDEX finger
      digitalWrite(mot1m, LOW);              
     }else if(rotateVal1<sensorValue1){
      digitalWrite(mot1p, LOW); //CLOSES INDEX finger
      digitalWrite(mot1m, HIGH);  
     }
     if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);
     }else if (rotateVal3>sensorValue3){
      digitalWrite(mot3p, HIGH); //OPENS RING finger
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, HIGH);
      digitalWrite(mot4m, LOW);                  
     }else if(rotateVal3<sensorValue3){
      digitalWrite(mot3p, LOW); //CLOSES RING finger
      digitalWrite(mot3m, HIGH);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, HIGH);  
     }      
     digitalWrite(mot2p, LOW);
     digitalWrite(mot2m, LOW);
   }else if(rotateVal1!=0 && rotateVal2!=0 && rotateVal3!=0){
     if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
      digitalWrite(mot1p, LOW);
      digitalWrite(mot1m, LOW);
     }else if (rotateVal1>sensorValue1){
      digitalWrite(mot1p, HIGH); //OPENS INDEX finger
      digitalWrite(mot1m, LOW);              
     }else if(rotateVal1<sensorValue1){
      digitalWrite(mot1p, LOW); //CLOSES INDEX finger
      digitalWrite(mot1m, HIGH);  
     }
     if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
      digitalWrite(mot2p, LOW);
      digitalWrite(mot2m, LOW);
     }else if (rotateVal2>sensorValue2){
      digitalWrite(mot2p, HIGH); //OPENS MIDDLE finger
      digitalWrite(mot2m, LOW);              
     }else if(rotateVal2<sensorValue2){
      digitalWrite(mot2p, LOW); //CLOSES MIDDLE finger
      digitalWrite(mot2m, HIGH);  
     } 
     
     if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
      digitalWrite(mot3p, LOW);
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, LOW);
      digitalWrite(mot4m, LOW);
     }else if (rotateVal3>sensorValue3){
      digitalWrite(mot3p, HIGH); //OPENS RING finger
      digitalWrite(mot3m, LOW);
      digitalWrite(mot4p, HIGH);
      digitalWrite(mot4m, LOW);                  
     }else if(rotateVal3<sensorValue3){
      digitalWrite(mot3p, LOW); //CLOSES RING finger
      digitalWrite(mot3m, HIGH);
      digitalWrite(mot4p, LOW);
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
   }
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
        rotateVal4 = serialData;
        if (pos0>rotateVal4){
          Stop(mot6p, mot6m); 
          }
        else{
          forward(mot5p, mot5m);
          Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);
        } 
      }
    case 5: 
      {
        serialRead();
        rotateVal5 = serialData;
        if (pos0>rotateVal5){
          Stop(mot5p, mot5m); 
          }
        else{
          forward(mot6p, mot6m);
          Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
        } 
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
        break;
      }    
   }     
 }
    Serial.print (encoderPosR);
    Serial.print ("\n"); 
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

void forward(int x, int y) {
  digitalWrite(x, LOW);
  //digitalWrite(AIN_2, HIGH);
  analogWrite(y, 93);
}

void reverse(int x, int y) {
  //digitalWrite(AIN_1, HIGH);
  analogWrite(x, 93);
  digitalWrite(y, LOW);
}

void Stop(int x, int y) {
  digitalWrite(x, LOW);
  digitalWrite(y, LOW);
}

void Read(int n, int encoderPinA, int encoderPinB, int encoderPos){
 // encoderPosR = encoderPos;
  
  n = digitalRead(encoderPinA);
  if ((encoderPinALastR == LOW) && (n == HIGH)) {
    if (digitalRead(encoderPinB) == LOW) {
      encoderPosR--;
    } else {
      encoderPosR++;
    }
    pos0 = encoderPosR;
    Serial.print (encoderPosR);
    Serial.print ("\n");
    encoderPos = encoderPosR;
  }
  encoderPinALastR = n;
  }
