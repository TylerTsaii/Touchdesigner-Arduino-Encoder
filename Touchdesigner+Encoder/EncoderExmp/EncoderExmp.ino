#include <Encoder.h>
Encoder knobLeft(2, 3);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

long positionLeft  = -999;

void loop() {
  long newLeft;
  newLeft = knobLeft.read();
  if (newLeft != positionLeft) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.println();
    positionLeft = newLeft;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
  }
}
