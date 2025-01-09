/*
  void setup() {
    Serial.begin(115200);
  }

  void loop() {
    if (Serial.available() > 0) {
      String inputString = Serial.readString();
      Serial.println(inputString);
    }
  }
*/
#include <SoftwareSerial.h>

//inizia una comunicazione seriale "virtuale" nei pin predef. 0(RX) e 1(TX)
SoftwareSerial Serial2(0, 1);

//stringhe di ID del mittente, stringhe del messaggio da mandare e ricevuto
String ID="", messageSend="", messageReceive="";

void setup() {
  //inizia la seriale col computer
  Serial.begin(115200);

  //ciclo che chiede all'utente un ID fino a quando non gliene dà uno valido
  bool exitf=false;
  do {
    Serial.println("Inserisci il tuo ID: ");
    while(!Serial.available()) {} //aspetta un messaggio

    ID = Serial.readString(); //legge la stringa

    if(ID == "") { //se è vuota:
      Serial.println("Inserisci un ID non vuoto.");
    } else { //sennò
      exitf = true; //esci dal ciclo
    }
  } while(!exitf);

  //inizia la comunicazione seriale "Serial2" con l'altro arduino in TX e RX
  Serial2.begin(115200);
}

void loop() {

  //per leggere i messaggi da inviare
  if(Serial.available()) { //se c'è una novità in "Serial":
    messageSend = Serial.readString(); //leggi la stringa
    sendMessage(messageSend); //vai alla funzione per mandarla
    messageSend = ""; //svuota il buffer di invio
  }

  if(Serial2.available()) { //se c'è una novità in "Serial2" (l'altro arduino):
    messageReceive = Serial2.readStringUntil("\f"); //leggi la stringa fino a \f
    //('f' è una specie di "fine messaggio") 
    Serial.println(messageReceive); //stampa in "Serial" il messaggio ricevuto
  }
}

void sendMessage(String msg) {
  msg.trim();
  Serial2.print(ID);
  Serial2.print(": ");
  Serial2.println(msg);
  Serial2.print("\f");

  Serial.print(ID);
  Serial.print(": ");
  Serial.println(msg);
}

