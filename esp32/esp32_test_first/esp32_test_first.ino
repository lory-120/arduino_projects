#include <Arduino.h>

int led=15;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("led acceso");
  delay(1000);
  digitalWrite(led, LOW);
  Serial.println("led spento");
  delay(1000);
}
