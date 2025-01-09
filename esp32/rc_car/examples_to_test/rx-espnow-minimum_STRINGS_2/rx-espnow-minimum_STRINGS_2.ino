#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h> //libreria fondamentale per ESP-NOW

//canale ESP-NOW
const uint8_t CHANNEL = 0; //Deve essere lo stesso del Master

void setup() {
  delay(1000); //aggiungo un delay così che la serial ha tempo di inizializzarsi

  Serial.begin(115200);

  //inizializza WiFi in modalità STA (o AP se preferisci)
  WiFi.mode(WIFI_AP); // Cambia in WIFI_AP se usi la modalità Access Point
  WiFi.softAP("RX_1", "RX_1_Password", CHANNEL, 0); //SSID, password, canale, isSSIDNascosta(bool)

  //inizializza ESP-NOW
  if(esp_now_init() != ESP_OK) { //ESP_OK è una macro che indica la risposta "ok, mi sono connesso"
    Serial.println("Errore nell'inizializzazione di ESP-NOW");
    return;
  }

  //registra la funzione callback per la ricezione di dati
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Pronto a ricevere messaggi");
}

/*
  Per ora nel loop() c'è solo una "mini-cli" creata da me, con i seguenti comandi:
  - setup: avvia il setup
  - test: vede se la scheda è viva, e rispondente
  - mac: restituisce il proprio ind. MAC
  Se non riconosce il comando, dà un messaggio di errore e via.
*/
void loop() {
  if(Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); //leggi i dati dalla porta seriale e li salva in una stringa

    //Controlla se il comando ricevuto è uno eseguibile
    if(command == "setup") { //setup
      Serial.println("Avvio setup...");
      setup();
    } else if(command == "test") { //test
      Serial.println("Hai chiamato, io rispondo. Sono funzionante.");
    } else if(command == "mac") { //mac
      Serial.println(WiFi.macAddress());
    } else { //errore
      Serial.print("Comando sconosciuto: ");
      Serial.println(command);
    }
  }
}

//funzione di callback per la ricezione dei dati
/*
  Quando si ricevono dei dati, si hanno i seguenti dati:
  - recv_info: struct contenente source e destination address
  - data: dati raw da interpretare. Possono essere char, int, double ecc.
  - len: n° di byte ricevuti
*/
void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *data, int len) {
  // Accesso all'indirizzo MAC del mittente
  const uint8_t *sender_mac = recv_info->src_addr;

  Serial.print("Messaggio ricevuto da: ");
  printMac(sender_mac); //funzione printMac che stampa il MAC
  Serial.println();

  Serial.print("Bytes ricevuti: ");
  Serial.println(len);

  /*
  PROBLEMA: SI RICEVE UN MESSAGGIO, MA STRANO:
  SCIAO BELLO!!!!1!�}�1�(zn�=�?������c��O��Xw�N>>p���ϣ#ֻ��P4o�j�z��J%v/����휱g����	�σ8z3�������ȭ<yqs@�kb�bIa�*I�z�K`�IE]���슪�H-0���=�cu\4��N����o�B6,�+o>��� �G9�Mu
  22:53:50.987 -> UIŀ��]�=�'����;[Q���ȏ�W�*t/�����u4oV�d������7�m�����)�I$
  22:53:53.017 -> Messaggio ricevuto da: 1c:69:20:30:21:b0
  !!!!!!!RISOLVERLO!!!!!!!
  risolto, il problema era il casting e il memcpy()
  */

  //converti i dati ricevuti in una stringa
  char message[len + 1]; // Aggiungi uno spazio per il terminatore di stringa
  memcpy(message, data, len); //copia char per char, da "data" a "message", iterando per "len" durata
  message[len] = '\0'; //carattere di fine stringa
  String strMessage = String(message); //"casting" da char a String

  Serial.print("Messaggio: ");
  Serial.println(strMessage);
}

//stampa il MAC address
void printMac(const uint8_t *mac_addr) {
  char macStr[18]; //17 + /0 = 18 caratteri
  sprintf(macStr, "%02x:%02x:%02x:%02x:%02x:%02x",
          mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
}