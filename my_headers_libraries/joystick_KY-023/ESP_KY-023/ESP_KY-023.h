/*
  Libreria per schede Espressif che permette di
  gestire segnali ricevuti dal modulo joystick
  KY-023.
*/
#include <Arduino.h>

class KY_023 {
  private:
    //attributi
    //pin dell'asse X e Y del joystick e del pulsante, frequenza e risoluzione
    int Xpin, Ypin, buttonPress;
    //valori dell'asse X e Y e del bottone
    int x, y;
    bool isPressed;

  public:    
    //metodo costruttore
    KY_023(int Xpin, int Ypin, int buttonPress) {
      this->Xpin = Xpin;
      this->Ypin = Ypin;
      this->buttonPress = buttonPress;

      this->x = 0;
      this->y = 0;
      this->isPressed = false;
    }

    //metodi get/set
    int getX() {
      this->x = analogRead(this->Xpin);
      return x;
    }
    int getY() {
      this->y = analogRead(this->Ypin);
      return y;
    }
    bool isButtonPressed() {
      int buttonVal = analogRead(buttonPress);

      this->isPressed = (buttonVal == 0) ? true : false;

      return (this->isPressed) ? true : false;
    }
};