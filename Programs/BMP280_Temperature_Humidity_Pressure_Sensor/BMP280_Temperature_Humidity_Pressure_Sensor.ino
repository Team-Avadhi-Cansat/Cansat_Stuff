#include <BMP280.h>
#include <Wire.h>

BMP280 sensor;

void setup() {
  Serial.begin(115200);
  delay(10);

  Wire.begin(21, 22);
  sensor.begin();
}

void loop() {
  uint32_t pressure = sensor.getPressure();
  float temperature = sensor.getTemperature();

  Serial.print("Pressure (in Pa) : "); Serial.println(pressure);
  Serial.print("Temperature (in C) : "); Serial.println(temperature);

  delay(2000);
}
