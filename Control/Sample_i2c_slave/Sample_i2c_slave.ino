// Include the required Wire library for I2C<br>#include <Wire.h>
#include <Wire.h>
int LED = 4;
int x = 0;
char c;
void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}


void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}


void loop() {

 // receiveEvent;
  //If value received is 0 blink LED for 200 ms
  if(c == 'a'){
      if (x == 100) {
        digitalWrite(LED, HIGH);
        Serial.print(x);
//        delay(200);
//        digitalWrite(LED, LOW);
//        delay(200);
      }
      //If value received is 3 blink LED for 400 ms
      else if (x == 200) {
        digitalWrite(LED, HIGH);
        delay(40);
      }
      else if (x = 50){
        digitalWrite(LED, LOW);
        delay(40);
      }
  }else if(c == 'b'){
    
       if (x == 100) {
        digitalWrite(LED, HIGH);
        Serial.print(x);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
      }
      //If value received is 3 blink LED for 400 ms
      else if (x == 200) {
        digitalWrite(LED, HIGH);
        delay(400);
        digitalWrite(LED, LOW);
        delay(40);
        digitalWrite(LED, HIGH);
        delay(400);
      }
      else if (x = 50){
        digitalWrite(LED, LOW);
        delay(40);
      }   
  }
}
