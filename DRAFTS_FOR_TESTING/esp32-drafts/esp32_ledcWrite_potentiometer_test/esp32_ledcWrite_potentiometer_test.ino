/*
  Sketch che, dato un valore analogico letto da un potenziometro da 0 a 4095,
  attua una luminosità analoga a quella letta dal potenziometro, tenendo conto
  della risoluzione di bit a cui opera la funzione ledcWrite.
*/
#include <Arduino.h>

#define POTPIN 32
#define LEDPIN 14

const int freq=1000, res=10; //modificare freq e res a piacimento
int potVal=0, ledVal=0;

void setup() {
  Serial.begin(115200);

  ledcAttach(LEDPIN, freq, res);
  pinMode(POTPIN, INPUT);
}

//si calcolano i valori massimi che si possono attuare al led (2^res)
const int ledMax=pow(2, res);

void loop() {
  potVal = analogRead(POTPIN); //leggi il valore del potenziometro
  ledVal = map(potVal, 0, 4095, 0, ledMax); //calcola il valore da attuare nel led
  
  ledcWrite(LEDPIN, ledVal); //attua il valore nel led
  

  //comunicalo nella porta seriale
  Serial.print(F("potVal: ")); Serial.print(potVal);
  Serial.print(F(" ledVal: ")); Serial.println(ledVal);

  delay(10); //cooldown
}
