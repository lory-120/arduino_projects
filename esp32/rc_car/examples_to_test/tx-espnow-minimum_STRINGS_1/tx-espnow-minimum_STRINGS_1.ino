#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h> //libreria fondamentale per ESP-NOW

// Indirizzo MAC dello slave (sostituisci con quello reale)
//uint8_t slave_mac[] = {0x64, 0xE8, 0x33, 0x84, 0x4E, 0x08}; //(è quello del mio seeed studio xiao esp32c3)
//uint8_t slave_mac[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //(da modificare)

// Canale ESP-NOW
const uint8_t CHANNEL = 0;  // Puoi cambiare il canale se necessario

//dati dello slave (che è un peer), salvati in una struct. Fa parte della libreria
esp_now_peer_info_t slave;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); //inizializza WiFi in modalità STA
  //Inizializza ESP-NOW
  if (esp_now_init() != ESP_OK) { //ESP_OK è una macro che indica la risposta "ok, mi sono connesso"
    Serial.println(F("Errore nell'inizializzazione di ESP-NOW"));
    return;
  }
  // Registra la funzione callback per la conferma di invio
  esp_now_register_send_cb(OnDataSent);

  Serial.print(F("Ricerca slave. Attendere prego."));
  do {
    Serial.print(F("."));
  } while(!scanForSlave());
  Serial.println(F("Slave trovato. Registro lo slave."));
  esp_now_add_peer(&slave);
  Serial.println(F("Slave registrato."));

  //SE SI HA L'INDIRIZZO MAC DEL DESTINATARIO, TOGLIERE QUESTO CODICE DAI COMMENTI E METTERE L'ALTRA PORZIONE TRA COMMENTI
  /*
  // Aggiungi il peer (dispositivo Slave)
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, slave_mac, 6);
  peerInfo.channel = CHANNEL;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Impossibile aggiungere il peer");
    return;
  }
  */

  Serial.println(F("\n***Pronto a inviare messaggi***"));
}

void loop() {
  //dati da inviare (lol)
  char *message = "SCIAO BELLO!!!!1!";

  //invia i dati e salva il risultato in result
  //funzione esp_now_send(indirizzo_mac_slave, contenutoì_messaggio_raw, lunghezz_char_stringa) manda il messaggio all'indirizzo mac specificato
  esp_err_t result = esp_now_send(slave.peer_addr, (uint8_t *)message, strlen(message));

  Serial.println((result == ESP_OK) ? F("Messaggio inviato con successo") : F("Errore nell'invio del messaggio")); //stampa esito

  if(Serial.available() > 0) {
    //Leggi i dati dalla porta seriale e li salva in una stringa
    String command = Serial.readStringUntil('\n');

    //Controlla se il comando ricevuto è uno eseguibile
    if(command == "setup") { //setup
      Serial.println(F("Avvio setup..."));
      setup();
    } else if(command == "test") { //test
      Serial.println(F("Hai chiamato, io rispondo. Sono funzionante."));
    } else if(command == "mac") { //mac
      Serial.println(WiFi.macAddress());
    } else { //comando errato
      Serial.print(F("Comando sconosciuto: "));
      Serial.println(command);
    }
  }

  delay(2000); //cooldown per non far esplodere la scheda
}

//(codice assolutamente non copiato e incollato lol)
bool scanForSlave() {
  Serial.println(F("Scansiono reti..."));
  int8_t scanResults = WiFi.scanNetworks(); //cerca reti wifi
  Serial.println(F("Scansione completata."));

  for(int i=0; i<scanResults; ++i) { //itera in tutte le reti trovate
    //salva SSID e BSSID in due stinghe, che è l'indirizzo mac del punto specifico wifi
    String SSID = WiFi.SSID(i);
    String BSSIDstr = WiFi.BSSIDstr(i);

    Serial.print(String(i)); Serial.print("rete: "); Serial.print(SSID); Serial.print(" | "); Serial.println(BSSIDstr); //per debug

    //si dà prescontato che tutti gli slave iniziano con "RX"
    if(SSID.indexOf("RX") == 0) {
      Serial.print("SSID: "); Serial.println(SSID);
      Serial.print("BSSID: "); Serial.println(BSSIDstr);

      int mac[6]; //array di int per immagazzinare il mac dello slave trovato
      if(6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x", &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5])) { //"se la formattazione del mac è corretta..."
        for(int j=0; j<6; ++j) { //aggiungi lo slave, inserendo il suo indirizzo mac nella variabile globale
          slave.peer_addr[j] = (uint8_t)mac[j];
        }
      }

      slave.channel = CHANNEL; //metti il canale per lo slave
      slave.encrypt = 0; //codifica del segnale allo slave (0 = no)
      return true;
      break;
    }
  }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) { //cosa fare quando si sono mandati i dati
  Serial.print(F("\r\nUltimo stato di invio pacchetto:\t"));
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Consegna riuscita" : "Consegna fallita");
}