//funzione che legge tutti gli stati e i valori e li trasforma in JSON
//dati da mandare: gli stati dei led e il valore del potenziometro
String writeJSONstates(int potVal) {
  String potStrVal; //stati sottoforma di stringhe (che spreco :/)

  //converti il valore potVal(int) in stringa
  potStrVal = String(potVal);
  
  //ora si scrive la stringa JSON da inviare
  JsonDocument message;
  message["potValue"] = potStrVal; //il valore del potenziometro

  String JSONtxt;
  serializeJson(message, JSONtxt); //crea il messaggio JSON vero e proprio e lo mette in JSONtxt

  return JSONtxt; //restituisce la stringa
}



//======================================================================================
//======================================================================================



//funzione che controlla una stringa, e in base ad essa scrive lo stato
bool checkHighLow(String str) {
  if(str == "H") {
    return HIGH;
  } else {
    return LOW;
  }
}

//per ricevere messaggi con WebSocket
//ricevo: stati dei led e valore del motore

JsonDocument received;

void WSevent(uint8_t num, WStype_t type, uint8_t *payload, size_t welength) {

  String payloadString = (const char *)payload;

  //*****PER DEBUG DEI DATI CHE SI RICEVONO*****//
  //Serial.print("payloadString= "); Serial.println(payloadString);

  if(type == WStype_TEXT) { //se ricevi del testo dal client:
    
    //si riceve gli stati dei 3 led e il valore del motore
    deserializeJson(received, payloadString);

  }

}

void getValues(bool &RState, bool &GState, bool &BState, int &motorVal) {
  RState = received["RState"].as<bool>();
  GState = received["GState"].as<bool>();
  BState = received["BState"].as<bool>();
  //Serial.println("stato dei led presi"); //(per debuggare lol)
  motorVal = received["motorVal"].as<int>();
  //Serial.println("valore motore preso"); //(per debuggare lol)
}

/*
- prendi la stringa JSON da WSevent
- deserializzala nella funzione getValues(), che restituisce i valori
*/



//======================================================================================
//======================================================================================



//funzioni per attuare il motore
void motorGo(int motorVal, int motorIn1, int motorIn2) {
  if(motorVal > 0) { //se il valore è >0, è cw
    ledcWrite(motorIn1, motorVal);
    ledcWrite(motorIn2, 0);
  } else if(motorVal < 0) { //se il valore è >0, è ccw
    motorVal *= -1; //ne inverte il segno
    ledcWrite(motorIn2, motorVal);
    ledcWrite(motorIn1, 0);
  } else { //l'unico caso rimasto è se il valore è 0
    ledcWrite(motorIn1, 255); //frena il motore
    ledcWrite(motorIn2, 255);
  }
}











