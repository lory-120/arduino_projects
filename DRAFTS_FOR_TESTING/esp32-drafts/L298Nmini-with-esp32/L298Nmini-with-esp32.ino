#include <Arduino.h>

const int IN1=18, IN2=19;
const int FREQ=5000, RES=8;

void setup() {
  Serial.begin(115200);
  ledcAttach(IN1, FREQ, RES);
  ledcAttach(IN2, FREQ, RES);
}

void loop() {
  int i;
  for(i=0; i<255; i++) { //gira in senso orario
    ledcWrite(IN1, i);
    delay(10);
  }


  ledcWrite(IN1, 255);
  delay(1000);
  ledcWrite(IN2, 255); //FRENA IL MOTORE immediatamente
  delay(5000);

  ledcWrite(IN2, 0);
  ledcWrite(IN1, 0);

  delay(5000);

  for(i=255; i>0; i--) {
    ledcWrite(IN1, i);
    delay(10);
  }

  delay(3000);

  for(i=0; i<255; i++) { //gira in senso antiorario
    ledcWrite(IN2, i);
    delay(10);
  }
  ledcWrite(IN2, 255);
  delay(5000);
  for(i=255; i>0; i--) {
    ledcWrite(IN2, i);
    delay(10);
  }

  delay(3000);
}
