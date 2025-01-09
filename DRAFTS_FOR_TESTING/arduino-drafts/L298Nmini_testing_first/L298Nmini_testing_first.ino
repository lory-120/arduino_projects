#include <MX1508.h> //libreria per il L298N, che è = per il MX1508

#define MOTOR_A1 9 //primo pin del controllo motore
#define MOTOR_A2 10 //secondo pin del controllo motore
#define NUMPWM 2 //numero di pin PWM con i quali controlleremo il motore
#define POTPIN A0 //pin del potenziometro

// MX1508 schematics(in Chinese) can be found here at: http://sales.dzsc.com/486222.html
/*
 * MX1508(uint8_t pinIN1, uint8_t pinIN2, DecayMode decayMode, NumOfPwmPins numPWM);
 * DecayMode must be FAST_DECAY or SLOW_DECAY,
 * NumOfPwmPins, either use 1 or 2 pwm. 
 * I recommend using 2 pwm pins per motor so spinning motor forward and backward gives similar response.
 * if using 1 pwm pin, make sure its pinIN1, then set pinIN2 to any digital pin. I dont recommend this setting because 
 * we need to use FAST_DECAY in one direction and SLOW_DECAY for the other direction.  
 */

MX1508 motorA(MOTOR_A1, MOTOR_A2, FAST_DECAY, NUMPWM); //crea l'oggetto che fa riferimento al motore

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  int potVal = analogRead(POTPIN);
  int motorVal = map(potVal, 0, 1023, -255, 255); //il range è (-255; 255) perché il motore può anche girare in senso ccw

  motorA.motorGo(motorVal); //attua il segnale
  Serial.println(motorA.getPWM()); //fai vedere nel monitor seriale la velocità (- o +)

  delay(10); //cooldown
}