#include <Arduino.h> //libreria per includere le funzioni di arduino in un esp32
#include <WiFi.h> //libreria per tutte le modalità di wifi

//definiamo i pin
#define redPin 12
#define greenPin 27
#define bluePin 25

void setup() {
  //settiamo la modalità dei pin
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(115200); //stabiliamo una comunicazione seriale a 115200 baud
  WiFi.mode(WIFI_STA); //mettiamo il wifi in "stationary mode" (la scheda è ora un AP)
  WiFi.disconnect(); //disconnetti da tutti gli AP, se era connesso a uno
  
  delay(1000); //cooldown
}

void loop() {
  //comunicazione seriale
  Serial.println("Ricerca di reti Wi-Fi...");
  setAllToLow();
  digitalWrite(redPin, HIGH);
  int networks = WiFi.scanNetworks(); //la funzione restituisce il numero di connessioni trovate

  if(networks > 0) { //se trova almeno una rete:
    setAllToLow(); //spegne tutti i led
    digitalWrite(greenPin, HIGH); //accendi il led verde

    //fai vedere tutte le reti trovate
    Serial.print(networks); Serial.println(" trovate.");
    for(int i=0; i<networks; i++) { //ora si stampano tutte le reti con le loro caratteristiche
      Serial.print(i+1); Serial.print(": "); Serial.print(WiFi.SSID(i)); //l'SSID della rete

      if(WiFi.encryptionType(i) == WIFI_AUTH_OPEN) { //se la rete è aperta:
        Serial.print(", aperta"); //stampa "aperta"
      } else {
        Serial.print(", chiusa"); //sennò stampa "chiusa"
      }

      Serial.print(" (segnale: "); Serial.print(WiFi.RSSI(i)); Serial.println(")");
      //la qualità del segnale: più il numero è vicino a 0, più il segnale è forte
    
      delay(50); //cooldown
    }
  } else { //se non trova nessuna rete:
    Serial.println("Nessuna rete trovata./nProva a cambiare luogo, o a caricare di nuovo il codice sulla scheda.");
    setAllToLow();
    blinkLED(redPin, 4);
  }
  Serial.println("\n<><><><><><><><><><><><><><><><><><><><><><><><><>\n");
  delay(7000);

}

void setAllToLow() { //funzione che spegne tutti i led
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void blinkLED(int pin, int n) {
  for(int i=0; i<n; i++) {
    digitalWrite(pin, HIGH);
    delay(400);
    digitalWrite(pin, LOW);
    delay(400);
  }
}
























