//definiamo i pin da utilizzare per l'I/O
const int inputPin = 7; //il pin di ingresso
const int outputPin = 8; //il pin di uscita

void setup() { //eseguita solo una volta, a meno che non sia richiamata nel loop()
  Serial.begin(9600); //inizializza la comunicazione seriale
  pinMode(inputPin, INPUT); //imposta il pin di input
  pinMode(outputPin, OUTPUT); //imposta il pin di output
}

void loop() { //eseguita all'infinito, fino a quando non si spegne la scheda o c'è un errore fatale
  bool pinState = digitalRead(inputPin); //leggi lo stato dal pin di input
  if(pinState == HIGH) { //se lo stato è HIGH:
    digitalWrite(outputPin, HIGH); //imposta lo stato del pin di output a HIGH (= acceso)
    Serial.print("Pulsante nel GPIO ");
    Serial.print(inputPin);
    Serial.println(" premuto."); //stampa una riga di messaggio nel Serial Monitor
  } else { //se invece è a LOW:
    digitalWrite(outputPin, LOW); //imposta lo stato del pin di output a LOW (= spento)
    Serial.print("Pulsante nel GPIO ");
    Serial.print(inputPin);
    Serial.println(" non premuto."); //stampa una riga di messaggio nel Serial Monitor
  }
}