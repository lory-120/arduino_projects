const int button_pin = 2, motor_pin = 9;
int state = 0;

void setup() {
  pinMode(motor_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {
  
  state = digitalRead(button_pin);

  if(state == HIGH) {
    digitalWrite(motor_pin, HIGH);
  } else {
    digitalWrite(motor_pin, LOW);
  }

}
