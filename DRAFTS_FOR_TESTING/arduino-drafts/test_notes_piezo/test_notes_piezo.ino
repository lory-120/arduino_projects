const int out=8;


void setup() {
  pinMode(out, OUTPUT);
}

int notes[] = {258, 288, 323, 343, 385, 434, 486, 520, 580, 640, 683, 753, 845, 947, 1020};
                                        //>
void loop() {

  int i;
  for(i=0; i<15; i++) {
    tone(out, notes[i], 400);
    delay(450);
  }
  delay(1000);

}
