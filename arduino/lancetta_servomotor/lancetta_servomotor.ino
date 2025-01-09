#include <Servo.h>

Servo mymotor;

const int inpin = A0;
int inval; //valore potenziometro
int angle;

void setup() {
  mymotor.attach(9);
  Serial.begin(9600);
}

void loop() {
  inval = analogRead(inpin);
  Serial.print("valore potenziometro: ");
  Serial.print(inval);

  angle = map(inval, 0, 1023, 0, 360);
  //map("variabile nella quale mettere il calcolo", "range min-max letto", "range min-max in cui trasformare il valore")

  Serial.print(", angolo calcolato: ");
  Serial.println(angle);

  //spostamento del servomotore all'angolo calcolato
  mymotor.write(angle);
  delay(100);
}
