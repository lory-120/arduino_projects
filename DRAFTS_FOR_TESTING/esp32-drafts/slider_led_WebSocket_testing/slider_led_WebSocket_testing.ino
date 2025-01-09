#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "Page.h"

#define SSID "Pentolo"
#define psw "lorenzo=2007"

#define LED1 27
#define LED2 25
#define MOTORPIN 32

WebServer server(80);
WebSocketsServer WebSocket = WebSocketsServer(81);

bool led1 = false, led2 = false;

void setup() {
  
  //definiamo i pin
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(MOTORPIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  WiFi.begin(SSID, psw);
  Serial.print("Connessione a "); Serial.print(SSID);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print("."); delay(500);
  }
  Serial.println("Connesso!");
  WiFi.mode(WIFI_STA);


  WebSocket.begin(); //inizia la comunicazione websocket
  WebSocket.onEvent(WSevent);
  Serial.println("<><><><><><><><> WebSocket avviato <><><><><><><><>");

  server.on("/", handleIndex);
  server.onNotFound(handle404); //quando immette una pagina non trovata
  server.begin(); //lancia il server
  Serial.println("<><><><><><><><> Server HTTP avviato <><><><><><><><>");
  Serial.print("IP: "); Serial.println(WiFi.localIP()); //fa vedere l'IP al quale connettersi
  
  delay(1500); //cooldown

}

bool LED1State = false, LED2State = false; //stati dei led
int motorVal = 0; //valore dem motore
JsonDocument message; //messaggio da inviare
JsonDocument received; //messaggio ricevuto

void loop() {
  WebSocket.loop(); //invia dati tramite websocket
  server.handleClient(); //gestisci la connessione con il client

  //controlla gli stati dei led e li attua
  if(LED1State == true) { 
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  if(LED2State == true) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  //attua il valore del motore
  analogWrite(MOTORPIN, motorVal);

  //per debuggare
  Serial.print("LED1: "); Serial.print(LED1State); Serial.print(" LED2: "); Serial.print(LED2State); Serial.print(" motorVal: "); Serial.println(motorVal);

  delay(500); //cooldown
}


void handleIndex() { //pagina che si mostra al client
  server.send(200, "text/html", HTMLIndex);
  Serial.println("Richiesta di connessione.");
}

void handle404() { //pagina di errore 404
  server.send(404, "text/html", HTML404);
  Serial.println("Richiesta pagina non trovata.");
}




//esempio di messaggio che si può ricevere
/*
  "LED1":true,
  "LED2":false,
  "motorVal":34209
*/

void WSevent(uint8_t num, WStype_t type, uint8_t *payload, size_t welength) { //TESTATO E CORRETTO
  String payloadStr = (const char *)payload;
  //Serial.print("Payload ricevuto: "); Serial.println(payloadStr); //payloadStr è un messaggio JSON //per debuggare

  if(type == WStype_TEXT) { //se si riceve del testo:
  //testo che riceve:
  //16:43:27.487 -> Payload ricevuto: {"motorValue":"1340","led1":false,"led2":false}

    deserializeJson(received, payloadStr); //deserializza il JSON
    //metti gli stati e i valori nelle variabili apposite
    LED1State = received["LED1"];
    LED2State = received["LED2"];
    motorVal = received["motorVal"];

  }

}








