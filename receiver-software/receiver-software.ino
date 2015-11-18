#include <IRremote.h>

const int RECV_PIN = 10; // PB6
const int LED_PIN = 11;  // PB7

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello!");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

int counter = 0;
unsigned long lastPulse = 0;
unsigned long lastCorrectPulse = 0;

void loop() {
  if (millis() - lastCorrectPulse > 200)
    digitalWrite(LED_PIN, LOW);

  if (irrecv.decode(&results)) {
    if(millis() - lastPulse > 300) {
      Serial.write('\r');
      Serial.write('\n');
    }

    lastPulse = millis();

    if(results.decode_type == SONY) {
      counter++;
      Serial.write('.');
      Serial.print(results.value);
      digitalWrite(LED_PIN, HIGH);
      lastCorrectPulse = millis();
    } else {
      Serial.write('*');
    }

    irrecv.resume(); // Receive the next value
  }
}
