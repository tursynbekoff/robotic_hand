#include <PID_v1.h>

//#define enc_th  A6 //thumb 
#define enc_p  A10 //pointing
#define enc_m  A9 //middle
#define enc_r  A8 //ring
#define enc_l  A7 //little
//#define enc_th_s  A11 //thumb  side

int encoder0PinA = 36;
int encoder0PinB = 40;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
long pos0 = 0;

int encoder1PinA = 24;
int encoder1PinB = 28;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;
long pos1 = 0;
int encoderPinALastR = 0;

int encoderPosR = 0;


//const int initB = {13};

const int FLEX_PINs[] = {A0, A1, A2, A4};//thumb, pointing, middle, thumb side
int pinCount = 4;
//int input, output; //for PID
double Setpoint, input, output;
int init_glove[] = {283, 300, 178, 415};//thumb, point middle thumb side
int fin_glove[] = {306, 510, 390, 445};
PID myPID(&input, &output, &Setpoint, 2, 1, 1, DIRECT);

void setup() {
  Serial.begin(9600);
 // pinMode(enc_th, INPUT);
 long pos0 = 0;
  pinMode(enc_p, INPUT);
  pinMode(enc_m, INPUT);
  pinMode(enc_r, INPUT);
  pinMode(enc_l, INPUT);
 // pinMode(enc_th_s, INPUT);

  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);


  Setpoint = 1;

  // pinMode(initB, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  myPID.SetMode(AUTOMATIC);
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(FLEX_PINs[thisPin], INPUT);
  }

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
   // Serial.print (encoderPosR);
    //Serial.print ("\n");
    encoderPos = encoderPosR;
  }
  encoderPinALastR = n;
  }



//bool initiate(){
//
//  *init_glove=readGlove();//open hand
//  delay(3000);
//  *fin_glove=readGlove();//closed hand
//
//  if (init_glove[0]!=0 && fin_glove[0]!=0 ){
//     return 1;
//     }else{
//         return 0;
//         }
//}

int saferange(int finger, int value) {
  if (finger == 2 && (value > 720 || value < 1016 )) {//
    if (value < 720) {
      value = 720;
    }
    else if (value > 1016) {
      value = 1016;
    }
    else {}
    return  map(value, 720, 1016, 0, 90);
  }
  else if (finger == 3 && (value > 750 || value < 1006 )) {
    if (value < 720) {
      value = 720;
    }
    else if (value > 1006) {
      value = 1006;
    }
    else {}
    return map(value, 750, 1023, 0, 90);
  }
  //  else if (finger == 4 && (value > 750 || value < 1023 )) {
  //    if (value < 720) {
  //      value = 720;
  //    }
  //    else if (value > 1016) {
  //      value = 1016;
  //    }
  //    else {}
  //    return map(value, 750, 1023, 0, 90);
  //  }
  else if (finger == 5 && (value > 5 || value < 260 )) {
    if (value < 750) {
      value = 750;
    }
    else if (value > 1023) {
      value = 1023;
    }
    else {}
    value = 1000 - value;
    return map(value, 750, 1023, 0, 90);
  }
  else if (finger == 0 && (value > 0 || value < 20 )) {//thumb
    if (value < 0) {
      value = 0;
    }
    else if (value > 20) {
      value = 20;
    }
    else {}
    // return map(value, 0, 40, 0, 90);
    return value;
  }
  else if (finger == 1 && (value > 0 || value < 20 )) {
    if (value < 0) {
      value = 0;
    }
    else if (value > 20) {
      value = 20;
    }
    else {}
    return map(value, 0, 20, 0, 20);
  }
  else {
    return 0;
  }
}

void motor (int finger, int toClose, int pwm) {
  if (toClose == 1) { //close
    analogWrite(finger * 2, pwm);
    analogWrite((finger * 2 + 1), 0);
  }
  else if (toClose == 0) { //open
    analogWrite(finger * 2 + 1, pwm);
    analogWrite((finger * 2), 0);
  }
  else { //stop
    analogWrite(finger * 2 + 1, 0);
    analogWrite((finger * 2), 0);
  }
}



void direction(int enc, int ref, int finger) {

  double pwm = 0;
  
  if (enc > 0 || enc==0) {
    int diff = 0;
    diff = ref - enc;
    input = diff;
    myPID.Compute();
  //Serial.println("Inside the direction " + String(diff));
    //Serial.println(String(diff)+" diff");
    //Serial.println(String(output)+" output");
    pwm = map(output, 0, 255, 190, 250 );
    //  Serial.println(String(output) + " PID");
    if (diff > 10) {
      Serial.println("closing finger " + String(finger));
      motor(finger, 1, pwm);//to close
      delay(1);
    } else if (diff < -10) {
      Serial.println("openning finger " + String(finger));
      motor(finger, 0, pwm); //to open
      delay(1);
    } else {
      Serial.println("Stopped finger " + String(finger));
      motor(finger, 2, 150);//to stop
      delay(1);
    }
  } else {
    motor(finger, 2, 0);
  }
}


void loop() {
  int ready = 0;

  // if (digitalRead(initB)==HIGH){
  //   ready=initiate();
  //  Serial.println("Ready! You can start");
  //}
  //  if (ready==1){
  int ref[6];

  int flex[] = {0, 0, 0, 0};
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    if (thisPin == 3) {
      flex[thisPin] = analogRead(FLEX_PINs[thisPin]);
    }
    else
    { flex[thisPin] = 1000 - analogRead(FLEX_PINs[thisPin]);
    }

    //Serial.print(" [" + String(init_glove[thisPin]) + "  " + String(flex[thisPin]) + "  " + String(fin_glove[thisPin]) + "] ");
    if (flex[thisPin] < init_glove[thisPin] ) {
      flex[thisPin] = init_glove[thisPin];
    }
    if (flex[thisPin] > fin_glove[thisPin] ) {
      flex[thisPin] = fin_glove[thisPin];
    }
    if (thisPin == 0) {

      ref[thisPin] = map(flex[thisPin], init_glove[thisPin], fin_glove[thisPin], 0, 20);
    }
    else if (thisPin==3){
      ref[thisPin] = map(flex[thisPin], init_glove[thisPin], fin_glove[thisPin], 0, 20);
      }
    else {
      ref[thisPin] = map(flex[thisPin], init_glove[thisPin], fin_glove[thisPin], 0, 90);
    }
  }
  ref[5] = ref[3];
  ref[3] = ref[2];
  ref[4] = ref[2];

Read(n0, encoder0PinA, encoder0PinB, encoder0Pos);

Read(n1, encoder1PinA, encoder1PinB, encoder1Pos);

  //  Serial.println();
  //  Serial.println(String(ref[0]) + "     " + String(ref[1]) + "      " +
  //                  String(ref[2]) + "      " + String(ref[3]) + "      " +
  //                  String(ref[4]) + "       " + String(ref[5]));
  //  Serial.println(String(saferange(2, analogRead(enc2))) + " " +
  //                 String(saferange(3, analogRead(enc3))) + " " +
  //                 String(saferange(4, analogRead(enc4))) + " " +
  //                 String(saferange(5, analogRead(enc5)))  );
  //  Serial.println(String(analogRead(enc_p)) + "     " + String(analogRead(enc_m)) + "      " +
  //                  String(analogRead(enc_r)) + "      " + String(analogRead(enc_l)) + "      " );
  //   String(analogRead(enc_th)) + "      " + String(analogRead(enc_th_s)));
//  Serial.println(String(saferange(2, analogRead(enc_p))) + "     " +
//                 String(saferange(3, analogRead(enc_m))) + "      " +
//                 String(saferange(3, analogRead(enc_r))) + "      " +
//                 String(saferange(3, analogRead(enc_l))) + "      " );
Serial.println(String(ref[0]) + "     " + String(ref[5]));

 Serial.println(String(saferange(0, encoderPosR)) + "     " +
                String(saferange(1, encoder1Pos)) + "     " 
                //String(saferange(2,analogRead(enc_p))) + "     " +
                // String(saferange(3, analogRead(enc_m))) + "      " +
                 //String(saferange(3, analogRead(enc_r))) + "      " +
                // String(saferange(3, analogRead(enc_l))) + "      " 
                 );

 // Serial.println(String(analogRead(A7)));
  // direction(saferange(2, analogRead(enc_p)), ref[1], 2);
//  direction(saferange(3, analogRead(enc_m)), ref[2], 3);
  direction(saferange(0, encoder0Pos), ref[0], 0);
  direction(saferange(1, encoder1Pos), ref[5], 1);
  // direction(saferange(3, analogRead(enc_m)), ref[4], 5);
  //direction(saferange(1, analogRead(enc_th)), ref[0], 1);
  //direction(saferange(6, analogRead(enc_th_s)), ref[3], 6);
  //  }
  // else{
 // delay(500);
  //  }


  //myPID.Compute();
  //Serial.print(String(analogRead(enc1)) + ' ');
  //Serial.print(String(analogRead(enc2)) + ' ');
  //Serial.print(String(analogRead(enc3)) + ' ');
  //Serial.print(String(analogRead(enc4)) + ' ');
  //   Serial.println("Here");



  //Serial.println();
 // delay(1);
}
