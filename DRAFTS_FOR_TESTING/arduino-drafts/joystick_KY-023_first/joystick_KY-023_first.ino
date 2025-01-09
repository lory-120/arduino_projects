/*
  programma che, letto il valore di un modulo joystick come KY-023,
  mostra i valori dell'asse X e Y (che sono potenziometri).
  Inoltre mostra se lo stick è premuto o no.
*/
#define XPIN A0 //dove si legge le X
#define YPIN A1 //dove si legge le Y
#define BUTTONPIN A2 //dove si legge lo stato del bottone

int X, Y; //valori logici assi 
int button; //stato del bottone
String buttonStr = ""; //stringa da mostrare nell'output seriale

void setup() {
  Serial.begin(115200); //inizia la comunicazione seriale
  delay(1000);

  //assegna il compito dei pin
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  //leggi i valori X, Y e lo stato del bottone
  X = analogRead(XPIN);
  Y = analogRead(YPIN);
  button = analogRead(BUTTONPIN);
  if(button==0) {
    buttonStr="true";
  } else {
    buttonStr="false";
  }

  //mostra i valori nella porta seriale
  Serial.print(F("X: "));
  Serial.print(X);
  Serial.print(F("\tY: "));
  Serial.print(Y);
  Serial.print(F("\tB: "));
  Serial.println(buttonStr);

  delay(50); //cooldown
}
