/*

***FUNZIONI UTILI:***
clearDisplay():
pulisce tutto quello che c'era nello schermo

setCursor(int x, int y):
date una x e una y, imposta il cursore a quelle coordinate come in un grafico
cartesiano, solo che parte dall'alto-sinistra.

setTextColor(COLOR):
imposta il colore con cui opereremo (es. per scrivere).

setTextSize(int size):
imposta la grandezza dei caratteri digitati sullo schermo.

print(String text):
data una stringa e impostati precedentemente il cursore, il colore e la grandezza (forse
anche il font), stampa la stringa.

drawLine(int x1, int y1, int x2, int y2, COLOR):
dati un punto A e un punto B (indicati con 4 coordinate), disegna una linea che parte
dal punto A al punto B.

drawRectangle(int x1, int y1, int x2, int y2, COLOR):
dati un punto A e un punto B (indicati con 4 coordinate), disegna un rettangolo che parte
dal punto A al punto B.
Il parametro COLOR imposta il colore del perimetro.

fillRectangle(int x1, int y1, int x2, int y2, COLOR):
stessa cosa di drawRect, ma lo riempie del colore COLOR.

display():
tutte le funzioni citate qua sopra sono inefficaci senza questa.
Infatti, serve per far vedere le cose impostate.

TUTTE LE FUNZIONI SONO ELENCATE NEL FILE Adafruit_SSD1306.h CHE E' OPEN SOURCE.

*/

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define POT_PIN 35
#define OLED_I2C_ADDRESS 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
 
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT);
 
void setup() {
  Serial.begin(115200);
  Serial.println("Setup iniziato.");

  if(!oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
    Serial.println("Errore, display oled non inizializzato.");
    while(true);
  }
  Serial.println("Display oled inizializzato.");

  oled.clearDisplay();
  //showHeader();
  //oled.display();
  oled.setCursor(0, 0);
  Serial.println("Setup finito.");
  delay(1500);
}
 
void loop() {
  int potVal = analogRead(POT_PIN);
  //Serial.println(potVal); //per debuggare lol

  printCenteredText(String(potVal));
  oled.display();
  delay(100);
}


void printCenteredText(String text) {
  Serial.println(text); //per debuggare lol

  oled.clearDisplay();

  oled.setTextSize(4);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);

  int16_t x1 = 0, y1 = 0;
  uint16_t w = 0, h = 0;
  oled.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  int16_t x = (OLED_WIDTH - (x1 + w)) / 2 + 2;
  int16_t y = (OLED_HEIGHT - (y1 + h)) / 2 + 2;
  oled.setCursor(x, y);

  oled.print(text);
}




