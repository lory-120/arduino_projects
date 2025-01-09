const int out=8;

/*QUESTO SKETCH HA IL SOLO SCOPO EDUCATIVO.
  NON INVOCA IN NESSUN MODO AL NAZISMO.   */

int notes[] = {258, 288, 323, 343, 385, 434, 486, 520};
int notes1[] = {258, 288, 323, 343, 385, 434, 486, 520, 580, 640, 683, 753, 845, 947, 1020};
const int _do=258, re=288, mi=323, fa=343, sol=385, la=434, si=486;
const int _domg=520, remg=580, mimg=640, famg=683, solmg=753, lamg=845, simg=947;

void setup() {
  pinMode(out, OUTPUT);
}

void loop() {
  delay(1300);
  tone(out, mi, 500); //AUF
  delay(900);
  tone(out, fa, 400); //DER
  delay(300);
  tone(out, sol, 300); //HEI-
  delay(550);
  tone(out, sol, 300); //-DEN
  delay(550);
  tone(out, sol, 300); //BLUHT
  delay(550);
  tone(out, _domg, 300); //EIN
  delay(550);
  tone(out, _domg, 300); //KLEI-
  delay(550);
  tone(out, mimg, 300); //-NES
  delay(550);
  tone(out, mimg, 600); //BLUUUUU-
  delay(900);
  tone(out, remg, 400); //-ME-
  delay(300);
  tone(out, _domg, 300); //-LEIN
  delay(1700);
  tone(out, si, 350); //UND
  delay(550);
  tone(out, _domg, 350); //DAS
  delay(550);
  tone(out, remg, 350); //HEIBT
  delay(1900);
  tone(out, mimg, 600); //EEEEEE
  delay(900);
  tone(out, remg, 400); //-RI-
  delay(300);
  tone(out, _domg, 300); //-KA
  delay(1500);
}