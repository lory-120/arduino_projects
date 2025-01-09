#include <esp_now.h>
#include <WiFi.h>

#define CHANNEL 1

uint8_t newData;

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP);
  WiFi.softAP("RX_1", "RX_1_Password", CHANNEL, 0);
  
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  /*Serial.print("I did this to data -> ");
  Serial.println(newData * 5);
  delay(3000);*/
}

/** callback when data is recv from Master **/
/*
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  Serial.print("I just received -> ");
  Serial.println(*data);
  memcpy(&newData, data, sizeof(newData));
}
*/

void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *data, int len) {
  // Access the sender's MAC address
  const uint8_t *sender_mac = recv_info->des_addr;

  Serial.print("I just received -> ");
  Serial.println(*data);
  memcpy(&newData, data, sizeof(newData));
  // Process the received data
  // ...
}
