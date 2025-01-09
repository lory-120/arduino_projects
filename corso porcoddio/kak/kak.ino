void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);
  Serial.println(F("ACCESO DIO ETRUSCO"));
  delay(1000);
  digitalWrite(7, LOW);
  Serial.println(F("uffa :("));
  delay(1000);
}
