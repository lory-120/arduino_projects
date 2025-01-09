int stato = LOW;

void setup() {
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  stato = digitalRead(8);
  if(stato == HIGH) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }
  delay(5);
}