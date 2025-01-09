#include <Arduino.h>
#include "ESP_KY-023.h"

const int Xpin=13, Ypin=12, buttonPress=14, freq=5000, res=9;
KY_023 joypad(Xpin, Ypin, buttonPress);

void setup() {
  Serial.begin(115200);
}

void loop() {
  String str = "X: " + String(joypad.getX()) + ", Y: " + String(joypad.getY()) + ", buttonPress: " + String(joypad.isButtonPressed());
  Serial.println(str);
  delay(10);
}
