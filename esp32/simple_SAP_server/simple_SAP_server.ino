/*
  Ogni server ha bisogno di 3 indirizzi specifici:
  - l'indirizzo IP locale, che identifica la scheda fisica;
  - la subnet mask, che identifica in quale piccola rete si trova la scheda
    (trattata come server);
  - il gateway predefinito, che permette di connettere con altre reti, accedendo così
    a internet.
*/
//IPAddress localIP(192,168,1,1);
//IPAddress subnet(255,255,255,0);
//IPAddress gateway(192,168,1,1);

#include <Arduino.h> //con questa libreria si può operare con le stringhe
#include <WiFi.h>
#include <WebServer.h> //libreria per mettere in modalità "Soft AP" (SAP) l'ESP32
#include <WebSocketsServer.h> //libreria per WebSocket
#include <ArduinoJson.h> //libreria per maneggiare i JSON

#include "WebPage.h" //il mio primo header file che contiene il testo raw delle pagine :)
#include "bigFunctions.h" //include le funzioni di invio e ricezione di dati e roba + complessa

//nome della rete (SSID) e password
#define ssid "Pentolo"
#define psw "lorenzo=2007"

//definiamo i pin
#define redPin 12
#define greenPin 27
#define bluePin 25
#define potPin 35

//pin dell'IC L298N mini per il motore
#define motorIn1 18
#define motorIn2 19

#define freq 1000 //frequenza aggiornamento dei valori analogici (l'esp32 funziona così)
#define res 8 //bit di risoluzione del segnale


WebServer server(80); //porta per l'HTTP (80 è di default, la più comune)
WebSocketsServer WebSocket = WebSocketsServer(81); //crea una porta WebSocket (81)


void setup() {
  
  Serial.begin(115200); //inizia una comunicazione seriale

  //dichiariamo i pin
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);
  //per il motore
  ledcAttach(motorIn1, freq, res);
  ledcAttach(motorIn2, freq, res);

  delay(1000); //cooldown

  WiFi.begin(ssid, psw); //tenta la connessione al wifi, date ssid e password
  Serial.print(F("Connessione a ")); Serial.print(ssid);
  while(WiFi.status() != WL_CONNECTED) { //stampa dei puntini durante la connessione
    Serial.print("."); delay(500);
  }
  Serial.println("");
  /*************************AGG. CASO IN CUI NON SI CONNETTE***************************/

  WiFi.mode(WIFI_STA); //imposta la modalità a STAtionary mode

  //metti la casistica del websocket (ce ne serve solo una perché si manda tutto in un unico file JSON)
  WebSocket.onEvent(WSevent);
  WebSocket.begin(); //inizia la comunicazione websocket
  Serial.println(F("<><><><><><><><> WebSocket avviato <><><><><><><><>"));

  //qui ci sono tutti i casi in cui l'utente si connesse alla scheda tramite la rete (solo 2 lol):
  server.on("/", handleIndex); //alla connessione
  server.onNotFound(handle404); //quando immette una pagina non trovata
  server.begin(); //lancia il server
  Serial.println(F("<><><><><><><><> Server HTTP avviato <><><><><><><><>"));
  Serial.print(F("IP: ")); Serial.println(WiFi.localIP());
  delay(2000); //cooldown
  
}


//variabili degli oggetti da controllare
bool RState = LOW, GState = LOW, BState = LOW; //stato dei led
int potVal, motorVal = 0; //valore potenziometro 0-4095 e motore -255 - 255
const int maxLedVal = pow(2, res); //calcola il valore massimo del PWM del LED (2^res)
JsonDocument message; //elemento JSON da inviare al client (per ora vuoto)
String JSONtxt = ""; //stringa JSON da inviare al client (per ora vuota)

void loop() {
  //gestisce le richieste server e websocket
  server.handleClient(); WebSocket.loop();
  //Serial.println("Handle avviati");

  getValues(RState, GState, BState, motorVal);
  //Serial.println("Funzione getValues fatta");

  ////////////!!!CREARE UNA FUNZIONE PER QUESTO!!!/////////////

  if(!RState) { //rosso
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
  }
  if(!GState) { //verde
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(greenPin, HIGH);
  }
  if(!BState) { //blu
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(bluePin, HIGH);
  }
  //Serial.println("Controlli agli stati dei led fatti");


  potVal = analogRead(potPin); //legge il valore del potenziometro

  motorGo(motorVal, motorIn1, motorIn2); //attua il valore del motore inviato dalla pagina

  JSONtxt = writeJSONstates(potVal); //funzione in bigFunctions
  //Serial.println(JSONtxt); //(per debuggare lol)

  WebSocket.broadcastTXT(JSONtxt); //manda il messaggio JSON ai client

  delay(100); //cooldown
}

void handleIndex() { //cosa fare quando un client si connette
  server.send(200, "text/html", HTMLIndex);
  Serial.println(F("Nuova connessione al server."));
}
 
void handle404() { //cosa fare quando la pagina non esiste
  server.send(404, "text/html", HTML404);
  Serial.println(F("Richiesta una pagina inesistente."));
}