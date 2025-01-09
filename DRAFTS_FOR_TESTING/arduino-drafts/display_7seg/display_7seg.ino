short int a=11, b=10, c=9, d=8, e=5, f=4, g=3, h=2; //i pin per il display 7seg
int display_pin[] = {a, b, c, d, e, f, g, h}; //array di pin

void setup() {
  int i; //indicatore

  for(i=2; i<11; i++) { //setta tutti i pin necessari come output
    pinMode(i, OUTPUT);
  }

  for(i=2; i<11; i++) { //imposta a 0V tutti i pin settati
    digitalWrite(i, LOW);
  }
}

void loop() {
  int i; //indicatore

  for(i=0; i<=9; i++) { //mostra tutti i numeri da 0 a 9
    writeOnDisplay(i, true); //"true" è il puntino in basso a destra
    delay(1000); //pausa 1 secondo
  }

}

// qui, se un segmento è HIGH, non è illuminato, nel display 7seg ad ANODO COMUNE
// se è a catodo comune, vale la cosa opposta
void writeOnDisplay(int n, bool dot) {
  int i;

  for(i=0; i<7; i++) {
    digitalWrite(display_pin[i], LOW);
  }
  delay(10);
  digitalWrite(a, LOW);

  
  switch(n) {
    case 0: //HIGH: a
      digitalWrite(a, HIGH);
    break;
    case 1: //HIGH: a, b, c, e, f
      digitalWrite(a, HIGH);
      delay(5);
      digitalWrite(b, HIGH);
      delay(5);
      digitalWrite(c, HIGH);
      delay(5);
      digitalWrite(e, HIGH);
      delay(5);
      digitalWrite(f, HIGH);
    break;
    case 2: //HIGH: b, g
      digitalWrite(b, HIGH);
      delay(5);
      digitalWrite(g, HIGH);
    break;
    case 3: //HIGH: b, e
      digitalWrite(b, HIGH);
      delay(5);
      digitalWrite(e, HIGH);
    break;
    case 4: //HIGH: c, e, f
      digitalWrite(c, HIGH);
      delay(5);
      digitalWrite(e, HIGH);
      delay(5);
      digitalWrite(f, HIGH);
    break;
    case 5: //HIGH: d, e
      digitalWrite(d, HIGH);
      delay(5);
      digitalWrite(e, HIGH);
    break;
    case 6: //HIGH: d
      digitalWrite(d, HIGH);
    break;
    case 7: //HIGH: a, b, e, f
      digitalWrite(a, HIGH);
      delay(5);
      digitalWrite(b, HIGH);
      delay(5);
      digitalWrite(e, HIGH);
      delay(5);
      digitalWrite(f, HIGH);
    break;
    case 8: //HIGH: nulla
    break;
    case 9: //HIGH: e
      digitalWrite(e, HIGH);
    break;
    default:
      for(i=0; i<8; i++) {
        digitalWrite(display_pin[i], HIGH);
      }
      for(i=0; i<4; i++) {
        digitalWrite(a, LOW);
        delay(400);
        digitalWrite(a, HIGH);
        delay(400);
      }
  }

  delay(10);

  if(dot) {
    digitalWrite(display_pin[8], HIGH);  
  } else {
    digitalWrite(display_pin[8], LOW);
  }

  delay(10);
}
