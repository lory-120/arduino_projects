/*
  Sketch che, dato un ESP32-WROOM-32D (o simili), fa illuminare un
  LED gradualmente, accendendolo e spegnendolo, usando la funzione
  ledcWrite (simile ad analogWrite).
*/
#include <Arduino.h>

/*ci serviranno 3 dati:
  - il pin in cui andremo ad operare;
  - la frequenza con cui andremo a far funzionare il led, quindi ogni
    quanto azioneremo il comando di intensità specifica;
  - la risoluzione in bit, cioè quanti valori digitali metteremo a disposizione
    (es res=8 -> 2^8=256 bit, quindi il range è 0-255).*/
const int pin=13, freq=1000, res=8;

void setup() {  
  ledcAttach(pin, freq, res); //dichiariamo il pin al quale faremo queste azioni
  //(i pin possono essere >1)
}

void loop() {
  int i=0; //indicatore
  for (i=0; i<255; i++) { //accendi il led in tutti i valori, cresc. da 0 a 255
    ledcWrite(pin, i);
    delay(1);  
  }
  for (i=255; i>0; i--) { //accendi il led in tutti i valori, decresc. da 255 a 0
    ledcWrite(pin, i);
    delay(1);  
  }
}

/*
  !!!!!ATTENZIONE!!!!!
  se all'inizio non abbiamo dichiarato il led nel void setup(),
  la funzione ledcWrite() ti manderà a fanculo e basta. :)
*/
