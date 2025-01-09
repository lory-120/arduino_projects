/*
  Questo sketch funzionerà SOLO con le schede ESP della Espressif
  (ESP32, ESP8266, Wemos D1 Mini, seeed studio ecc.)
*/

class L298N {
  public:
    //attributi
    //pin del motore, frequenza e risoluzione
    int in_1, in_2, speed, freq, res;

    //metodo costruttore
    L298N(int in_1, int in_2, int freq, int res) {
      this->in_1 = in_1;
      this->in_2 = in_2;
      this->freq = freq;
      this->res = res;
      ledcAttach(in_1, freq, res);
      ledcAttach(in_2, freq, res);
      this->speed = 0;
    }

    //metodi get/set
    int getCurrentSpeed() {
      return this->speed;
    }

    //metodi della funzione
    void motorGo(int speed) {
      this->speed = speed;
      if(speed > 0) {
        ledcWrite(in_1, speed);
        ledcWrite(in_2, 0);
      } else if(speed < 0) {
        ledcWrite(in_1, 0);
        ledcWrite(in_2, -speed);
      } else {
        ledcWrite(in_1, 0);
        ledcWrite(in_2, 0);
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
      ledcWrite(in_1, 255);
      ledcWrite(in_2, 255);
    }
};