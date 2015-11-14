#include <IRremote.h>

// IRLED = P1 / PB1

const int RACER_ID = 0xa90;

IRsend irsend;

void setup() { }

void loop() {
  irsend.sendSony(RACER_ID, 12);
  delay(50);
}
