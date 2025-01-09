#include <Servo.h>
Servo the_servo;
const int piezo=A0, button=2, y_led=3, g_led=4, r_led=5;
const int high_knock=100, low_knock=10;
int n_knock, knock_val;
bool button_val, locked=false;

void setup() {
  the_servo.attach(9);
  pinMode(y_led, OUTPUT);
  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(4800);
  digitalWrite(g_led, HIGH);
  the_servo.write(0);
  Serial.println("Scatola aperta.");
}

void loop() {
  if(!locked) {
    button_val = digitalRead(button);

    if(button_val) {
      locked = true;
      digitalWrite(g_led, LOW);
      digitalWrite(r_led, HIGH);
      the_servo.write(90);
      Serial.println("Scatola chiusa.");
      delay(1000);
    }

  }

  Serial.print("Valore del piezo: ");
  Serial.println(knock_val);

  if(locked) {
    knock_val = analogRead(piezo);
    
    if(n_knock<3 && n_knock>0) {
      if(check_knock(knock_val)) {
        n_knock++;
      }
      Serial.print(3-n_knock);
      Serial.println(" tocchi mancanti per sbloccare.");
    }
    
    if(n_knock >= 3) {
      locked = false;
      the_servo.write(0);
      delay(20);
      digitalWrite(g_led, HIGH);
      digitalWrite(r_led, LOW);
      Serial.println("Scatola aperta.");
      n_knock=0;
    }
  }  

}

bool check_knock(int val) {
  if(val>low_knock && val<high_knock) {
    digitalWrite(y_led, HIGH);
    delay(50);
    digitalWrite(y_led, LOW);
    Serial.print("Valido tocco: ");
    Serial.println(val);
    return true;
  } else {
    Serial.print("Tocco invalido: ");
    Serial.println(val);
    return false;
  }
}







