// define led according to pin diagram in article
#include <Arduino.h>
const int led = D10; // there is no LED_BUILTIN available for the XIAO ESP32C3.

void setup() {
  //init serial
  Serial.begin(115200);
  // initialize digital pin led as an output
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on
  Serial.println("on");
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off
  Serial.println("off");
  delay(1000);               // wait for a second
}