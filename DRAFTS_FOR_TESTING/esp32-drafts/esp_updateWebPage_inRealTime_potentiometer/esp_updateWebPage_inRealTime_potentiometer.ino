//includi tutte le librerie necessarie per il wifi e la scheda stessa
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WebSocketsServer.h>
#include <WebServer.h>

#include "RealTimePage.h" //includi il file header che contiene la pagina HTML

//SSID e password della rete esterna
#define SSID "Pentolo"
#define psw "lorenzo=2007"

WiFiMulti WiFiMulti; //crea un oggetto WiFiMulti per potersi connettere a più AP contemporaneamente
WebServer server(80); //crea una porta server
WebSocketsServer webSocket = WebSocketsServer(81); //crea una porta WebSocket dove si invieranno i dati in tempo reale


void setup() {

  Serial.begin(115200); //comunicazione seriale
  delay(1000);

  WiFiMulti.addAP(SSID, psw); //aggiungi un AP

  Serial.print("Connessione a "); Serial.print(SSID); Serial.println(" in corso");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  webSocket.begin(); //inizia la comunicazione websocket
  Serial.println("WebSocket avviato");

  //inserisci tutte le casistiche (solo 2 lol)
  server.on("/", handleMain);
  server.onNotFound(handleNotFound);

  server.begin(); //avvia il server
  Serial.println("Server ESP32 avviato");

}

void handleMain() { //cosa fare quando l'utente si connette
  server.send(200, "text/html", html_template); 
}
void handleNotFound() { //cosa fare quando l'utente immette una pagina inesistente
  server.send(404, "text/html", "<html><body><p>404 Error</p></body></html>");
}


String value; //valore del potenziometro

void loop() {
  webSocket.loop(); //invia dati tramite websocket
  server.handleClient(); //gestisci la connessione con il client

  value = (String) analogRead(35); //leggi il valore del potenziometro dal pin 35, trasformalo in String e mettilo in value
  webSocket.broadcastTXT(value); //invia il dato tramite websocket

  delay(150); //cooldown
}
