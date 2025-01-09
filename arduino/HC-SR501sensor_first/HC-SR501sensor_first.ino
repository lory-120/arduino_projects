const int led=7, sensor=10;

void setup() {
  pinMode (sensor, INPUT);
  pinMode (led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool pir = digitalRead(2);

  if(pir == 1) {
    digitalWrite(13, HIGH);
    Serial.println("Intruso!");
  } else {
    digitalWrite(13, LOW);
  }

  delay (10);
}