const int sensorpin = A0;
const float baselinetemp = 20.0;

void setup() {
  Serial.begin(9600);
  for(int npin=2; npin<5; npin++) {
    pinMode(npin, OUTPUT);
    digitalWrite(npin, LOW);
  }
}

void loop() {
  float s_value = analogRead(sensorpin); //valore del sensore
  Serial.print("Valore sensore: ");
  Serial.print(s_value);

  float voltage = (s_value/1024)*5.0; //calcolo del voltaggio generato dal sensore
  Serial.print(", tensione (V): ");
  Serial.print(voltage); //voltaggio calcolato da "s_value"

  float tempc = (voltage-0.5)*100; //temperatura calcolata da "s_value"
  Serial.print(", gradi °C: ");
  Serial.println(tempc); 

  if(tempc < baselinetemp+2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(tempc >= baselinetemp+2 && tempc < baselinetemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(tempc >= baselinetemp+4 && tempc < baselinetemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(tempc > baselinetemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(5);
}
