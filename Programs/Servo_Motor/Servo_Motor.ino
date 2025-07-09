#include <ESP32Servo.h>

const int servoPin = 33;

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  for(int pos = 0; pos <= 180; pos++) {
      servo.write(pos);
      Serial.println(pos);
      delay(20);
  }

  for(int pos = 180; pos >= 0; pos--) {
      servo.write(pos);
      Serial.println(pos);
      delay(20);
    }

}
