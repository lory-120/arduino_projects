const int c_pin1 = 2;
const int c_pin2 = 3;
const int on_pin = 9;
const int switch_direc = 4;
const int io_switchstate = 5;
const int potenz = A0;
int iostate = 0;
int prev_iostate = 0;
int direc_state = 0;
int prev_direc_state = 0;
int mon = 0;
int mospeed = 0;
int modirec = 1;

void setup() {
  pinMode(switch_direc, INPUT);
  pinMode(io_switchstate, INPUT);
  pinMode(c_pin1, OUTPUT);
  pinMode(c_pin2, OUTPUT);
  pinMode(on_pin, OUTPUT);
  digitalWrite(on_pin, LOW);
}

void loop() {
  
  iostate = digitalRead(io_switchstate);    //legge stato del pulsante per accendere il motore
  delay(1);
  direc_state = digitalRead(switch_direc);  //legge stato del pulsante per cambiare verso di rotazione motore
  mospeed = analogRead(potenz)/4;           //legge il valore del potenziometro e lo converte in velocità

  if(iostate != prev_iostate) {             //SE LO STATO ATTUALE DI ON/OFF E' DIVERSO DALLO STATO PRECEDENTE:
    if(iostate == HIGH) {                   //SE "iostate" E' HIGH:
      mon = !mon;                           //inverti lo stato di acensione del motore (con una variabile)
    }
  }
  if(direc_state != prev_direc_state) {     //SE LO STATO IND. DI DIREZIONE DI ROTAZ. E' DIVERSO DA QUELLO PRECEDENTE:
    if(direc_state == HIGH) {               //SE "direc_state" E' HIGH:
      modirec = !modirec;                   //inverti la direzione del motore (con una variabile)
    }
  }

  if(modirec == 1) {                        //SE LA DIREZIONE DEL MOTORE E' 1:
    digitalWrite(c_pin1, HIGH);             //metti carica + al polo +
    digitalWrite(c_pin2, LOW);              //metti carica - al polo -
  } else {                                  //SENNO'
    digitalWrite(c_pin1, LOW);              //metti carica - al polo +
    digitalWrite(c_pin2, HIGH);             //metti carica + al polo -
  }

  if(mon == 1) {                            //SE IL MOTORE E' ACCESO:
    analogWrite(on_pin, mospeed);           //accendi il motore con la velocità (tensione PWM) insicata dal pot. (mospeed)
  } else {                                  //SENNO'
    analogWrite(on_pin, 0);                 //non dare carica al motore
  }

  prev_direc_state = direc_state;           //metti gli stati attuali di direzione e di accensione come stati precedenti
  prev_iostate = iostate;

}
