void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

// 2 -> 4
// 3 -> 5

int pin2, pin3;

void loop() {
  pin2 = digitalRead(2);
  switch(pin2) {
    case HIGH:
    digitalWrite(4, HIGH);
    break;
    case LOW:
    digitalWrite(4, LOW);
    break;
  }

  pin3 = digitalRead(3);
  switch(pin3) {
    case HIGH:
    digitalWrite(5, HIGH);
    break;
    case LOW:
    digitalWrite(5, LOW);
    break;
  }

}
