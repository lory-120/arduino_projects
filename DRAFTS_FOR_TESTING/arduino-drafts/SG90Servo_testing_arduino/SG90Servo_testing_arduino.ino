/*
Sketch dove, dato un servomotore SG90 e un potenziometro, si prende il valore di
quest'ultimo e lo si attua nel servomotore.
*/

#include <Servo.h>

#define POT_PIN A0
#define SERVO_PIN 9

Servo servo;

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  int potVal = analogRead(POT_PIN);
  int degrees = map(potVal, 0, 1023, 0, 180);
  servo.write(degrees);

  Serial.println(degrees);

  delay(100);
}
