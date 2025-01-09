/*
Sketch che, dato un potenziometro e un servomotore SG90, permette di controllare
il servomotore con il potenziometro (0-360°).
*/

/*
#include <Arduino.h>

#define POT_PIN 25
#define SERVO_PIN 32


void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  ledcAttach(SERVO_PIN, 5000, 12);
}

void loop() {
  //int angle = map(analogRead(POT_PIN), 0, 4095, 0, 65535);
  int value = analogRead(POT_PIN);

  Serial.println(value);
  analogWrite(SERVO_PIN, value);

  delay(10);
}
*/


#include <ESP32Servo.h>

#define SERVO_PIN 32

Servo myservo;  // Create servo object to control a servo

void setup() {
  myservo.attach(SERVO_PIN);  // the number of the servo pin
}

void loop() {
  myservo.write(90);  // tell servo to go to position in degrees
  delay(1000);
  myservo.write(0);   // tell servo to go to position in degrees
  delay(1000);
}