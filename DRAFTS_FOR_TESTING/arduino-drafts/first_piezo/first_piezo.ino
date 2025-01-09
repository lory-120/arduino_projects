int s_value;
int s_lo = 1023, s_hi = 0;
const int ledpin = 13;

void setup() {
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);

  while(millis()<5000) {
    s_value = analogRead(A0);
    if(s_value>s_hi) {
      s_hi = s_value;
    }
    if(s_value<s_lo) {
      s_lo = s_value;
    }
  }
  digitalWrite(ledpin, LOW);
}

void loop() {
  s_value = analogRead(A0);
  int pitch = map(s_value, s_lo, s_hi, 500, 2000);
  tone(8, pitch, 20);
  delay(7);
}