#include <ESP_L298N.h>

const int in_1=26, in_2=27, freq=5000, res=6;

L298N motor(in_1, in_2, freq, res);

void setup() {
  Serial.begin(115200);
  Serial.println("Comunicazione seriale inizializzata.");
}

void loop() {
  Serial.println("Loop avviato.");
  int i;
  for(i=0; i<pow(2, res); i++) {
    motor.motorGo(i);
    delay(100);
    Serial.println(String(motor.getCurrentSpeed()));
  }
  motor.motorStop();
  delay(1000);
  for(i=0; i>-pow(2, res); i--) {
    motor.motorGo(i);
    delay(100);
    Serial.println(String(motor.getCurrentSpeed()));
  }
  delay(1000);
  motor.motorBreak();
  delay(1000);

  motor.motorGo(pow(2, res));
  delay(3000);
}

int pow(int base, int exp) {
  int result=1;
  for(int i=1; i<=exp; i++) {
    result *= base;
  }
  return result;
}