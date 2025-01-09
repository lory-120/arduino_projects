/*
  Sketch che testa la funzionalità di un drifer motore L293D (Vmax=36V, Imax=600mA).
  Si collega anche un potenziometro nel pin A3, per controllare la direzione e
  velocità del motore.
*/

#define POTPIN A0
#define INPUT1 A1
#define INPUT2 A2

void setup() {
  Serial.begin(115200);
}

void loop() {
  int potVal = analogRead(POTPIN);
  int motorVal = map(potVal, 0, 1023, -255, 255);
  if(motorVal >= 0) {
    analogWrite(INPUT2, 0);
    analogWrite(INPUT1, motorVal);
  } else {
    analogWrite(INPUT1, 0);
    int tmp = map(motorVal, 0, -255, 0, 255);
    Serial.println(tmp);
    analogWrite(INPUT2, tmp);
  }
  //Serial.println(motorVal);
}
