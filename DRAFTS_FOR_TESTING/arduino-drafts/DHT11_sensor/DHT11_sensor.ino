#include <DHT.h> //libreria per i sensori DHT

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE); //dichiara l'oggetto che rappresenta il sensore DHT11

void setup() {
  Serial.begin(115200);
  dht.begin(); //inizia la comunicazione con in DHT
}

void loop() {
  delay(500); //cooldown

  //Leggere la temperatura e/o l'umidità ci vuole circa 250ms
  float humidity = dht.readHumidity(); //leggi umidità in %
  float temperature = dht.readTemperature(); //leggi temperatura in Celsius (di default)

  //Controlla se ci sono errori nella lettura di temperatura, umidità o entrambe
  if(isnan(humidity) && isnan(temperature)) {
    Serial.println(F("DHT totalmente fallito."));
    return;
  } else if(isnan(humidity)) {
    Serial.println(F("Lettura umidità fallita."));
    return; //si mette questo in modo tale che stoppa il loop e restituisce 0
  } else if(isnan(temperature)) {
    Serial.print(F("Lettura temperatura fallita."));
    return; //si mette questo in modo tale che stoppa il loop e restituisce 0
  }

  Serial.print(F("Umidità: ")); //F() significa che prende la stringa da un puntatore che punta nella memoria flash, così si risparmia RAM (+ efficiente)
  Serial.print(humidity);
  Serial.print(F("%  Temperatura: "));
  Serial.print(temperature);
  Serial.println(F("°C "));
}