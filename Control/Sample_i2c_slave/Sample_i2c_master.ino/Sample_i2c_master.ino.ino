// Include the required Wire library for I2C<br>#include 
#include <Wire.h>
int ledPin = 9;
byte x = 50;

unsigned long serialData;
int inbyte; 
int digitalState;
int pinNumber;
int analogRate;


void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600); 
}
void loop() {

//        Wire.beginTransmission(9); // transmit to device #9
//        Wire.write("a");
//        Wire.write(x);              // sends x 
//        //Wire.write("/n");
//        Wire.endTransmission();
//        
//        //x++;
//        delay(100);

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
        digitalWrite(ledPin, LOW);
        Serial.print("LED is OFF \n");
        break;
      }
    case 3:
      {
        digitalWrite(ledPin, HIGH);
        Serial.print("LED is ON \n");
        break;
     }
    case 4:
      {  
        serialRead();
        x = serialData; 
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("a");
        Wire.write(x);              // sends x 
        Wire.endTransmission();    // stop transmitting

       

        break;
      }
    case 5:
      { 
        serialRead();
        x = serialData; 
        Wire.beginTransmission(9); // transmit to device #9
        Wire.write("b");
        Wire.write(x);              // sends x 
        Wire.endTransmission();    // stop transmitting

       
        delay(500);
        break;
      }
//     case 6: 
//      {
////        digitalWrite(AIN_1, LOW);
////        digitalWrite(AIN_2, LOW);
////        digitalWrite(BIN_1, LOW);
////        digitalWrite(BIN_2, LOW);
//
//        
//        delay(1000);
////        rotateVal7 = encoder0PosR;
// //       rotateVal8 = encoder1PosR;
////        rotateVal1 = sensorValue1;
////        rotateVal2 = sensorValue2;
////        rotateVal3 = sensorValue3;               
//        Serial.print("Command of STOP");
//        Serial.print("\n");
//        break;                         
//      }      
//    case 7:
//      {
//
//
//        Serial.print("Value of pos Axis:  ");
// //       Serial.print(encoder0PosR);
//        Serial.print("\t");
//        Serial.print("\t");
//        Serial.print("Value of pos JOINT:  ");
// //       Serial.print(encoder1PosR);
//        Serial.print("\n");
//        break;
//      } 
//    case 8:
//      {
//
//        rotateVal7 = 0;
//        rotateVal8 = 0;           
//        break;
//      }     
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
