#include <SoftwareSerial.h>

const int rxPin = 2; // Pin RX collegato al TX dell'altro Arduino
const int txPin = 3; // Pin TX collegato al RX dell'altro Arduino

SoftwareSerial mySerial(rxPin, txPin);

bool connected = false;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Connesso all'altro Arduino!");
  connected = true;
}

void loop() {
  if (mySerial.available() > 0) {
    String incomingMsg = mySerial.readStringUntil('\n');
    Serial.println(incomingMsg);
  }

  if (connected) {
    Serial.print("> ");
    while (Serial.available() == 0);
    String outgoingMsg = Serial.readStringUntil('\n');
    mySerial.println(outgoingMsg);
  }
}