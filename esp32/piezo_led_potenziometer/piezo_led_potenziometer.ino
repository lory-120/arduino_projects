#include <Arduino.h>

short int led=19, piezo=23, potenziometer=15;

void setup() {
  Serial.begin(250000);
  pinMode(led, OUTPUT);
  //pinMode(piezo, OUTPUT);
}

void loop() {
  int value = analogRead(potenziometer); //leggi valore del potenziometro

  //ora si calcola il segnale digitale
  int convertedVal = map(value, 0, 4095, 0, 65535);
  Serial.println(convertedVal);

  //ora si scrivono i valori al led e al piezo
  analogWrite(led, convertedVal);
  tone(piezo, convertedVal, 1);

  //fai riposare un pochino la scheda
  delay(100);
}
