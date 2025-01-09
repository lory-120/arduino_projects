// il progetto funziona bene se la temperatura dello spazio dove si opera è di ca. 20°C
#include <LiquidCrystal.h>

const int rs=8, en=9, db4=10, db5=11, db6=12, db7=13; //pin per lo schermo lcd
const int trig=3, echo=A0; //pin per il sensore

//dichiaro lo schermo lcd con tutti i suoi pin
LiquidCrystal lcd(rs, en, db4, db5, db6, db7);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Benvenuto/a");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
}

void loop() {
  //leggi la distanza
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //adesso, si aspetta che nel pin "echo" ci sia un valore HIGH
  //quando c'è, si conta il tempo e si smette di contare quando
  //c'è di nuovo LOW
  long time = pulseIn(echo, HIGH);

  //velocità del suono a 20°C: 343,8 m/s = 0,03438 cm/us (microsecondo)
  //quindi si assume che nell'ambiente ci siano 20°C
  float distance = (0.03438*time)/2;

  //scrivi sullo schermo lcd
  lcd.setCursor(0, 1);
  lcd.print("Distanza: " + String(distance) + " cm");

  delay(10);

  lcd.setCursor(0, 0);
  if(distance <= 10) {
    lcd.print("Distanza corta");
  } else if(distance > 10 && distance <= 20) {
    lcd.print("Distanza media");
  } else if(distance >= 30){
    lcd.print("Distanza lunga");    
  }

  delay(70);
}
