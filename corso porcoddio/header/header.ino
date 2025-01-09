#include "headerFile.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  int n;
  bool go = false;

  if (Serial.available()) {
    n = Serial.parseInt();
    go = true;
  }

  if(go) {
    printSaluto(n);
    go = false;
  }
}
