#include <CapacitiveSensor.h>
CapacitiveSensor cap_sensor = CapacitiveSensor(4, 2);

int limit=1000;
const int led=12;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  long sensor_val = cap_sensor.capacitiveSensor(30);
  Serial.println(sensor_val);
  
  if(sensor_val > limit) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(10);
}