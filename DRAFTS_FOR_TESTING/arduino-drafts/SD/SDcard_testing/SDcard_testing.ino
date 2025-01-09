#include <SD.h>
#include <SPI.h>

File file;

int cs = 10; //pin "chip select"

void setup() {
  Serial.begin(115200);
  pinMode(cs, OUTPUT);

  delay(2000); //cooldown

  //inizializza la scheda SD con comunicazione SPI
  if(SD.begin()) {
    Serial.println("Scheda SD pronta all'uso.");
  } else {
    Serial.println("Errore nell'inizializzare la scheda SD.");
    return;
  }

  //ora si crea un file .txt
  file = SD.open("test.txt", FILE_WRITE);
  //se il file è stato aperto per bene, scrivici:
  if(file) {
    Serial.println("Inserisci quello che vuoi scrivere nel file: ");
    String str = Serial.readString();
    file.println(str);
    file.close();
    Serial.println("Stringa scritta.");
  } else {
    Serial.println("Errore nella creazione/apertura del file.");
  }

  //ora si legge il file:
  file = SD.open("test.txt");
  if(file) {
    Serial.println("Leggendo file da te scritto: \n");
    //stampa tutto il file, char dopo char
    while(file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Errore nell'apertura del file.");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
