const int inpin=A0, outpin=11;
float sval=0, lval=0, ill=0;

void setup() {
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);
}

//meno la stanza è illuminata, più il led è acceso

void loop() {
  sval = analogRead(inpin);
  delay(1);

  lval = sval/4;
  ill = map(sval, 0, 1023, 255, 0);

  Serial.print("luce rilevata 0-255:\t");
  Serial.print(lval);
  Serial.print("\tluce generata proporzionalmente: \t");
  Serial.println(ill);
  
  analogWrite(outpin, ill);
}