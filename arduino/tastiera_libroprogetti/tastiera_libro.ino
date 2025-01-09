//questo programma è dal libro dei progetti, E NON FUNZIONA

int buttons[6];

int notes[] = {262, 294, 330, 349};
const int tonepin = 8;

void setup() {
  buttons[0] = 2;
  Serial.begin(9600);
  pinMode(tonepin, OUTPUT);
}

void loop() {
  int val_tastiera = analogRead(A0);
  Serial.println(val_tastiera);

  if(val_tastiera==1023) {
    tone(tonepin, notes[0]);
  } else if(val_tastiera>=990 && val_tastiera<=1010) {
    tone(tonepin, notes[1]);
  } else if(val_tastiera>=505 && val_tastiera<=515) {
    tone(tonepin, notes[2]);
  } else if(val_tastiera>=5 && val_tastiera<=10) {
    tone(tonepin, notes[3]);
  } else {
    noTone(8);
  }
  delay(5);
}
