/*
  Questo sketch funzionerà SOLO con le schede Arduino
  (UNO R3/R4, MEGA, Leonardo ecc.)
*/

class L298N {
  public:
    //attributi
    //pin del motore
    int in_1, in_2, speed;

    //metodo costruttore
    L298N(int in_1, int in_2) {
      this->in_1 = in_1;
      this->in_2 = in_2;
      this->speed = 0;
    }

    //metodi get/set
    int getCurrentSpeed() {
      return this->speed;
    }

    //metodi della funzione
    void motorGo(int speed) {
      if(speed > 0) {
        analogWrite(in_1, speed);
        analogWrite(in_2, 0);
      } else if(speed < 0) {
        analogWrite(in_1, 0);
        analogWrite(in_2, -speed);
      } else {
        analogWrite(in_1, 0);
        analogWrite(in_2, 0);
      }
    }

    void invertDirection() {
      this->speed = -this->speed;
    }

    void motorStop() {
      this->speed = 0;
      motorGo(this->speed);
    }

    void motorBreak() {
      analogWrite(in_1, 255);
      analogWrite(in_2, 255);
    }
};