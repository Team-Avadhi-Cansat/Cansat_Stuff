#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 18
#define BMP_MISO 19
#define BMP_MOSI 23
#define BMP_CS 5

Adafruit_BMP280 bmp280(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(100);   
  Serial.println("BMP280 Test");
  unsigned status;

  status = bmp280.begin(0x76);
  if(!status) {
      Serial.println("No Sensor Found");
      Serial.print("SensorID was: 0x"); Serial.println(bmp280.sensorID(),16);
      Serial.print("        ID of 0xFF probably means a bad 13/02/2025dress, a BMP 180 or BMP 085\n");
      Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
      Serial.print("        ID of 0x60 represents a BME 280.\n");
      Serial.print("        ID of 0x61 represents a BME 680.\n");
      while (1) delay(10);
  }

  bmp280.setSampling(
    Adafruit_BMP280::MODE_NORMAL,           //Operating Mode
    Adafruit_BMP280::SAMPLING_X2,           //Temp. Oversampling
    Adafruit_BMP280::SAMPLING_X16,
    Adafruit_BMP280::FILTER_X16,           //Filtering
    Adafruit_BMP280::STANDBY_MS_500        //Standby Time
  );
}

void loop() {
  Serial.print("Temperature (in C): "); Serial.println(bmp280.readTemperature());
  Serial.print("Pressure (in Pa): "); Serial.println(bmp280.readPressure());
  Serial.print("Approx Altitude (in m): "); Serial.println(bmp280.readAltitude(1013.25));

  Serial.println();
  delay(2000);
}
