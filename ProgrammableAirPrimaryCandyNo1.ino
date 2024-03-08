//Primary
#include <programmable_air.h>

const int transmitPin1 = 7;
const int transmitPin2 = 8;
const int transmitPin3 = 9;

void setup() {
initializePins();
pinMode(transmitPin1, OUTPUT);
pinMode(transmitPin2, OUTPUT);
pinMode(transmitPin3, OUTPUT);
}

void loop() {
Serial.println("Airbag 1 Blowing");
switchOnPump(1, 65
);
  blow();
// Activate Primary pump 1, blow via valve 2, close valves Primary 1 & 3
digitalWrite(transmitPin1, HIGH);
digitalWrite(transmitPin2, HIGH);
// Vent Airbags 2 & 3 via valves Secondary 1 & 3

delay(1000);
Serial.println("Airbag 1 Vent");
 switchOffPump(1);
vent();  
// Deactivate pump Primary 1, vent via valve Primary 1

Serial.println("Airbag 2 Blowing");
switchOnPump(2, 55);
  setValve(3, OPEN);
  digitalWrite(transmitPin1, LOW);
// Activate Primary pump 2, open valve Primary 3
digitalWrite(transmitPin2, HIGH);
// Vent Airbag 3 by opening Secondary valve 1

delay(1000);

Serial.println("Airbag 2 Vent");
 switchOffPumps();
vent();
// Deactivate Primary pump 2, vent via valve 3

Serial.println("Airbag 3 Blowing");
// Transmit the pin state to Secondary 
digitalWrite(transmitPin1, HIGH);
digitalWrite(transmitPin2, LOW);

 delay(1200);
 Serial.println("Airbag 3 Vent");
}
