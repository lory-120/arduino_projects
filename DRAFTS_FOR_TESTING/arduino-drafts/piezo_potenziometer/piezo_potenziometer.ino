/*
Si collega un piezo e un potenziometro alla breadboard, e in base alla
rotazione della manovella del potenziometro, il pitch del piezo è sempre più alto.
C'è anche un led che indica quanto sta suonando il piezo.
*/
const int piezo=8, led=6;

void setup() {
  pinMode(piezo, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(500000);
}

void loop() {
  float pval = analogRead(A0);
  float pitch = map(pval, 0, 1023, 0, 1200);
  float light = map(pval, 0, 1023, 0, 255);
  tone(piezo, pitch, 10);
  analogWrite(led, light);

  Serial.print("Potenziometro: ");
  Serial.print(pval);
  Serial.print(", suono: ");
  Serial.print(pitch);
  Serial.print(", led: ");
  Serial.println(light);
}
