#include <Arduino.h>

#define potPin 35

void setup() {
  Serial.begin(115200);
  pinMode(potPin, INPUT);
}

int convertedVal;

void loop() {
  int potVal = analogRead(potPin);
  //Serial.println(potVal);

  convertedVal = map(potVal, 0, 4095, 0, 65535);

  Serial.println(convertedVal);

  delay(10); //cooldown
}