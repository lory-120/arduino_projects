const int in_sx = 2, out_sx = 3, in_dx = 13, out_dx = 12;

void setup() {
  pinMode(in_sx, INPUT);
  pinMode(out_sx, OUTPUT);
  pinMode(in_dx, INPUT);
  pinMode(out_dx, OUTPUT);
}

int s_sx = 0, s_dx = 0;

void loop() {
  s_sx = digitalRead(in_sx);
  s_dx = digitalRead(in_dx);

  // Controllo se è stato premuto il pulsante sinistro
  if (s_sx == HIGH) {
    while (s_sx == HIGH) {
      startBlink(out_sx);
      delay(300);
      stopBlink(out_sx);
      delay(300);
      s_sx = digitalRead(in_sx);
    }
  }

  // Controllo se è stato premuto il pulsante destro
  if (s_dx == HIGH) {
    while (s_dx == HIGH) {
      startBlink(out_dx);
      delay(300);
      stopBlink(out_dx);
      delay(300);
      s_dx = digitalRead(in_dx);
    }
  }
}

void startBlink(int pin) {
  digitalWrite(pin, HIGH);
}

void stopBlink(int pin) {
  digitalWrite(pin, LOW);
}