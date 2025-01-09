/*
var1 = analogRead(pin)
var2 = map(var1 fromMin, fromMax, toMin, toMax)
analogWrite()
*/
int variabileLeggi, output;
const int potPin=A0, ledPin=10;

void setup() {
  Serial.begin(500000);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  variabileLeggi = analogRead(potPin);
  output = map(variabileLeggi, 0, 1023, 0, 255);
  analogWrite(ledPin, output);
  //Serial.println(output);
  scriviPunti(output);
  delay(50);
}

void scriviPunti(int output){
  int nPunti = map(output, 0, 255, 0, 90);
  for(int i=0; i<=nPunti; i++) {
    Serial.print(".");
  }
  Serial.println("");
}
