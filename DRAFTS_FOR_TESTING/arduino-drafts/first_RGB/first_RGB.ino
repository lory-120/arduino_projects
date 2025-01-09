const int r_pin=10, g_pin=9, b_pin=11;
const int r_sensorpin=A0, g_sensorpin=A1, b_sensorpin=A2;
int r_value=0, g_value=0, b_value=0;
int r_sensorval=0, g_sensorval=0, b_sensorval=0;

void setup() {
  Serial.begin(9600);
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
}

void loop() {
  //leggo i valori dati dai sensori, che NON sono quelli reali
  r_sensorval = analogRead(r_sensorpin);
  delay(5);
  g_sensorval = analogRead(g_sensorpin);
  delay(5);
  b_sensorval = analogRead(b_sensorpin);

  //calcolo i valori veri dei colori RGB
  r_value = r_sensorval/4;
  g_value = g_sensorval/4;
  b_value = b_sensorval/4;

  Serial.print("Valori reali del sensore \t RED: ");
  Serial.print(r_value);
  Serial.print("\t GREEN: ");
  Serial.print(g_value);
  Serial.print("\t BLUE: ");
  Serial.println(b_value);

  delay(5);
  /*associo i valori analogici letti (0-255) di RGB e li metto come
    intensità del singolo LED RGB*/
  analogWrite(r_pin, r_value);
  analogWrite(g_pin, g_value);
  analogWrite(b_pin, b_value);
}
