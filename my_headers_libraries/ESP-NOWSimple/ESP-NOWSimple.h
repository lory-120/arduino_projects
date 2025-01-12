/**
 * Libreria per schede Espressif, che semplifica l'uso della libreria ESP-NOW.
*/

/*
  Parametri comuni:
  - uint8_t CHANNEL - Il canale ESP-NOW comune al master e tutti gli slave.

  Funzioni comuni:
  - MACToString(uint8_t *macAddr) - restituisce il MAC address come stringa, prendendo un array di uint8_t.
*/

/*
  Parametri:
  - String slaveSsid - l'SSID dello Slave.
  - uint8_t mac[] - il MAC dello Slave.
  Funzioni:
  - scanForSlave() trova uno slave.
    scanForSlave(String slaveSsid) - Si può mettere anche una stringa come parametro, che è l'SSID dello slave che si cerca.
    scanForSlave(uint8_t &mac[]) - Si può anche mettere un MAC address, per connettersi ad esso. (!!! mettere l'operando address-of all'array del mac)
    Un parametro obbligatorio è il canale (int, costante). Se la funzione non ha altri parametri, si connette al primo slave che trova.
*/
class Master {
  private:
    const uint8_t CHANNEL;
    String slaveSsid = "";
    uint8_t mac[];
  public:
    //metodi costruttore
    Master(uint8_t CHANNEL) {
      this->CHANNEL = CHANNEL;
    }
    Master(uint8_t CHANNEL, String slaveSsid) {
      this->CHANNEL = CHANNEL;
      this->slaveSsid = slaveSsid;
    }
    Master(uint8_t CHANNEL) {
      this->CHANNEL = CHANNEL;
      this->mac = *mac;
    }

    //metodi get/set
    uint8_t getMac() {
      return this->mac[];
    }
    uint8_t getChannel() {
      return this->CHANNEL;
    }

    //metodi della funzione
    
}


/*
  Funzioni:
  - messageToString(uint8_t *data, int len) - converte i byte ricevuti in una stringa.
    messageToInt(uint8_t *data, int len) - in intero.
    messageToFloat(uint8_t *data, int len) - in float.
    messageToDouble(uint8_t *data, int len) - in double.
    messageToBool(uint8_t *data, int len) - in booleano.
*/
class Slave {

}