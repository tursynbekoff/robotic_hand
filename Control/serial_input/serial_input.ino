
int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorPin2 = A2;
int sensorPin3 = A0;

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

int mot1p = 7;       // Motor 1  POINT  OPENING  sensor 1
int mot1m = 6;       //                 CLOSING

int mot2p = 13;      // Motor 2 MIDDLE  OPENING  sensor 2
int mot2m = 12;      //                 CLOSING

int mot3p = 10;      // Motor 3  RING   OPENING  sensor 3
int mot3m = 11;      //                 CLOSING

int mot4p = 5;       // Motor 4  PINKY  OPENING
int mot4m = 4;       //                 CLOSING

int mot5p = 9;      // Motor 5
int mot5m = 8;

int mot6p = 3;      // Motor 6
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
}

void loop() {

   sensorValue1 = analogRead(sensorPin1);
   sensorValue2 = analogRead(sensorPin2);
   sensorValue3 = analogRead(sensorPin3);

   if((rotateVal1-sensorValue1)>=-5 && (rotateVal1-sensorValue1)<=5 ){
    digitalWrite(mot1p, LOW);
    digitalWrite(mot1m, LOW);
   }else if (rotateVal1>sensorValue1){
    digitalWrite(mot1p, HIGH); //OPENS INDEX finger
    digitalWrite(mot1m, LOW);              
   }else if(rotateVal1<sensorValue1){
    digitalWrite(mot1p, LOW); //CLOSES INDEX finger
    digitalWrite(mot1m, HIGH);  
   }else{
    digitalWrite(mot1p, LOW);
    digitalWrite(mot1m, LOW);    
   }

   if((rotateVal2-sensorValue2)>=-5 && (rotateVal2-sensorValue2)<=5 ){
    digitalWrite(mot2p, LOW);
    digitalWrite(mot2m, LOW);
   }else if (rotateVal2>sensorValue2){
    digitalWrite(mot2p, HIGH); //OPENS INDEX finger
    digitalWrite(mot2m, LOW);              
   }else if(rotateVal2<sensorValue2){
    digitalWrite(mot2p, LOW); //CLOSES INDEX finger
    digitalWrite(mot2m, HIGH);  
   }else{
    digitalWrite(mot2p, LOW);
    digitalWrite(mot2m, LOW);    
   }

   if((rotateVal3-sensorValue3)>=-5 && (rotateVal3-sensorValue3)<=5 ){
    digitalWrite(mot3p, LOW);
    digitalWrite(mot3m, LOW);
    digitalWrite(mot4p, LOW);
    digitalWrite(mot4m, LOW);
   }else if (rotateVal3>sensorValue3){
    digitalWrite(mot3p, HIGH); //OPENS INDEX finger
    digitalWrite(mot3m, LOW);
    digitalWrite(mot4p, HIGH);
    digitalWrite(mot4m, LOW);                  
   }else if(rotateVal3<sensorValue3){
    digitalWrite(mot3p, LOW); //CLOSES INDEX finger
    digitalWrite(mot3m, HIGH);
    digitalWrite(mot4p, LOW);
    digitalWrite(mot4m, HIGH);  
   }else{
    digitalWrite(mot3p, LOW);
    digitalWrite(mot3m, LOW);   
    digitalWrite(mot4p, LOW);
    digitalWrite(mot4m, LOW);
        
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
        Serial.print("Value of rotation:  ");
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
        Serial.print("Value of rotation:  ");
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
        Serial.print("Value of rotation:  ");
        Serial.print(rotateVal3);
        Serial.print("\n");
        break;
      }

    case 7:
      {
        Serial.print("S 1: ");
        Serial.print(sensorValue1 );
        Serial.print("\t");    
      
        Serial.print("  S 2: ");
        Serial.print(sensorValue2);
        Serial.print("\t");
      
        Serial.print("S 3: "); 
        Serial.print(sensorValue3);
        Serial.print("\t"); 

        Serial.print("inVal1: "); 
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
 delay(100);
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
