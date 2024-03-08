//Secondary:
#include <programmable_air.h>

const int receivePin1 = 7;
const int receivePin2 = 8;
const int receivePin3 = 9;

void setup() {
  initializePins();
  pinMode(receivePin1, INPUT);
  pinMode(receivePin2, INPUT);
  pinMode(receivePin3, INPUT);
}

void loop() {
  int receivedState1 = digitalRead(receivePin1);
  int receivedState2 = digitalRead(receivePin2);
  int receivedState3 = digitalRead(receivePin3);

 if (receivedState1 == LOW) {
    Serial.println("Airbag 2 Blowing");
    switchOffPumps();
    setValve(1, OPEN); // vent airbag 3
    setValve(2, CLOSE);
    setValve(3, CLOSE);
  } else if (receivedState2 == LOW) {
    Serial.println("Airbag 3 Blowing");
    switchOnPump(1, 85);
      // Inflate airbag 3
      setValve(1, CLOSED); 
      setValve(2, OPEN);
      setValve(3, OPEN); // vent airbag 2
  } else {
    Serial.println("Airbags 2 and 3 Venting");
  switchOffPumps();
    setValve(1, OPEN); // vent airbag 3
    setValve(2, CLOSE);
    setValve(3, OPEN); // vent airbag 2
  }

  delay(100);

}
