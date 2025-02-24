#include <Wire.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Wire.begin(21, 22);
  
  Serial.println("Scanning I2C devices...");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(address, HEX);
      delay(5);
    }
  }
}

void loop() {}
