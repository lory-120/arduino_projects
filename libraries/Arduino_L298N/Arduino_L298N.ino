#include "Arduino_L298N.h"

const int in_1=9, in_2=10;

L298N motor(in_1, in_2);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int i;
  for(i=0; i<255; i++) {
    motor.motorGo(i);
    delay(5);
    Serial.println(String(motor.getCurrentSpeed()));
  }
  motor.motorStop();
  delay(1000);
  for(i=0; i>-255; i--) {
    motor.motorGo(i);
    delay(5);
  }
  delay(1000);
  motor.motorBreak();
  delay(1000);
}
