  
const int buttonPin1 = 11;
const int buttonPin2 = 2;  
int AIN_1 = 6;
int AIN_2 = 5;
int BIN_1 = 10;
int BIN_2 = 9;
int LED = 8;
int buttonState1 = 0;
int buttonState2 = 0;
  
int encoder0PinA = 3;
int encoder0PinB = 4;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
long pos0 = 0;

int encoder1PinA = 12;
int encoder1PinB = 7;
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
  pinMode(LED, OUTPUT);
  //Serial.println("start"); 
  Serial.begin (19200);
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


void af(){
  
      if (pos0>20){
      Stop(AIN_1, AIN_2); 
      }
      else{
          forward(AIN_1, AIN_2);
          Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);
      }
  }

void ar(){
  
      if (pos0<-20){
      Stop(AIN_1, AIN_2); 
      }
      else{
          reverse(AIN_1, AIN_2);
          Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);
      }
  }

void br(){
  
      if (pos0>150){ //150
      Stop(BIN_1, BIN_2); 
      }
      else{
          //forward(BIN_1, BIN_2);
          reverse(BIN_1, BIN_2);
          Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
      }  
  }

 void bf(){
  
      if (pos0<-150){ //-150
      Stop(BIN_1, BIN_2); 
      }
      else{
            //reverse(BIN_1, BIN_2);
            forward(BIN_1, BIN_2);
            Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
      } 
  } 



void loop() {


    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);



    if (pos0>=20) {
      digitalWrite (LED, HIGH);
    }
    else {
       digitalWrite (LED, LOW);
    }
    
    if (buttonState1 == HIGH ) {  
//    af();
      br();
     // reverse(BIN_1, BIN_2);
     // Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);
    } 
    
  
    else if (buttonState2 == HIGH){
//    ar();
    bf();
//      forward(BIN_1, BIN_2);
    //  Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);     
    }
    
    else {
     Stop(BIN_1, BIN_2); 
     //Stop(AIN_1, AIN_2);
    }   
}
