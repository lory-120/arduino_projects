#include <esp_now.h>
//#include <ESP32-ESPNow.h>
#include <WiFi.h>

#define CHANNEL 1

int nAttemptSetup = 0;

uint8_t newData;

void setup() {
  nAttemptSetup++;
  delay(1000);

  Serial.begin(115200);
  Serial.println("Serial iniziato.");

  WiFi.mode(WIFI_AP);
  Serial.println("Modalità SAP iniziata.");
  WiFi.softAP("RX_1", "RX_1_Password", CHANNEL, 0);
  Serial.println("SAP configurato.");
  
  esp_now_init();
  Serial.println("esp now inizializzato.");
  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("esp now configurato.");

  Serial.println("Setup finito.");
  Serial.print("Tentativo di setup finito: ");
  Serial.println(String(nAttemptSetup));
}

void loop() {
  /*Serial.print("I did this to data -> ");
  Serial.println(newData * 5);
  delay(3000);*/  

  // Controlla se ci sono dati disponibili sulla porta seriale
  if(Serial.available() > 0) {
    //Leggi i dati dalla porta seriale e li salva in una stringa
    String command = Serial.readStringUntil('\n');

    //Controlla se il comando ricevuto è uno eseguibile
    if(command == "setup") {
      Serial.println("Avvio setup...");
      setup();
    } else if(command == "test") {
      Serial.println("Hai chiamato, io rispondo. Sono funzionante.");
    } else if(command == "mac") {
      Serial.println(WiFi.macAddress());
    } else {
      Serial.print("Comando sconosciuto: ");
      Serial.println(command);
    }
  }
}

/** callback when data is recv from Master **/
/*
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  Serial.print("I just received -> ");
  Serial.println(*data);
  memcpy(&newData, data, sizeof(newData));
}
*/

void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *data, int len) {
  // Access the sender's MAC address
  const uint8_t *sender_mac = recv_info->des_addr;

  Serial.print("I just received -> ");
  Serial.println(*data);
  memcpy(&newData, data, sizeof(newData));
  // Process the received data
  // ...
}
