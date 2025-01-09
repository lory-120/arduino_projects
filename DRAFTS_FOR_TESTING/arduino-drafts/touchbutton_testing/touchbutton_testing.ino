/*
  Sketch che testa la funzionalità di un pulsante touch.
*/

#define PIN 8

void setup() {
  pinMode(PIN, INPUT);
  Serial.begin(115200);  
}

void loop() {
  if(digitalRead(PIN)) {
    Serial.println("1");
  } else {
    Serial.println("0");
  }
  delay(50);
}
