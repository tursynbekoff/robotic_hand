  
const int buttonPin1 = 11;
const int buttonPin2 = 2;  
int AIN_1 = 12;
int AIN_2 = 13;
int BIN_1 = 2;
int BIN_2 = 3;
//int LED = 8;
int buttonState1 = 0;
int buttonState2 = 0;
  
int encoder0PinA = 28;
int encoder0PinB = 32;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
long pos0 = 0;

int encoder1PinA = 36;
int encoder1PinB = 40;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
long pos1 = 0;

int encoderPosR = 0;
//int encoderPos = 0;


unsigned long time;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
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
  Serial.begin (19200);
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
int encoderPinALastR = 0;


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

//void MoveFrwd() {
//  if (pos>20){
//  Stop(); 
//  }
//  else{
//      forward();
//      Read(n0, encoder0PinA, encoder0PinALast, encoder0PinB, encoder0Pos, pos0);
//  }
//}
//
//void MoveBkwd() {
//  if (pos<-20){
//  Stop(); 
//  }
//  else{
//      reverse(AIN_1,AIN_2);
//      Read();
//  }
//}

void af(){
  
      if (pos0>40){
      Stop(AIN_1, AIN_2); 
      }
      else{
          forward(AIN_1, AIN_2);
          Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);
      }
  }

void ar(){
  
      if (pos0<0){
      Stop(AIN_1, AIN_2); 
      }
      else{
          reverse(AIN_1, AIN_2);
          Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);
      }
  }

void br(){
  
      if (pos0>350){
      Stop(BIN_1, BIN_2); 
      }
      else{
          reverse(BIN_1, BIN_2);
          Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
      }  
  }

 void bf(){
  
      if (pos0<0){
      Stop(BIN_1, BIN_2); 
      }
      else{
            forward(BIN_1, BIN_2);
            Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
      } 
  } 

  

void loop() {

    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);

  //  Serial.println(voltage);
  //  Serial.print("\n"); 


    if (voltage < 3.53 && voltage > 3.0){
       Stop(BIN_1, BIN_2); 
     //  Stop(AIN_1, AIN_2);
//       digitalWrite (LED, LOW);
      }
    else if(voltage < 3.530){
    //  af();
      bf();
      //Stop(AIN_1, AIN_2);
    } 
    
    else if(voltage > 3.00) {
    //  ar();
      br();
      //Stop(AIN_1, AIN_2);
//      digitalWrite(LED, HIGH);
    }

}
