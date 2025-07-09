#include <Wire.h>
#include <SPI.h>
#include <MPU9250_asukiaaa.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 27
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#define MPU_SDA 18
#define MPU_SCL 19

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
MPU9250_asukiaaa mpu; 

float aX, aY, aZ, gX, gY, gZ;
float temperature, pressure, altitude; 

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.setWire(&Wire);
    while (!Serial) delay(100);
    Serial.println("BMP280 Test");
    unsigned status;
    status = bmp.begin(0x76);
    if(!status) {
      Serial.println("No Sensor Found");
      Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
      Serial.print("        ID of 0xFF probably means a bad 13/02/2025dress, a BMP 180 or BMP 085\n");
      Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
      Serial.print("        ID of 0x60 represents a BME 280.\n");
      Serial.print("        ID of 0x61 represents a BME 680.\n");
      while (1) delay(10);
    }

    bmp.setSampling(
      Adafruit_BMP280::MODE_NORMAL, 
      Adafruit_BMP280::SAMPLING_X2, 
      Adafruit_BMP280::SAMPLING_X16, 
      Adafruit_BMP280::FILTER_X16, 
      Adafruit_BMP280::STANDBY_MS_500
    );

    mpu.beginAccel();
    mpu.beginGyro();
}

void loop() {
  mpu.accelUpdate();
  mpu.gyroUpdate();

  aX = mpu.accelX();
  aY = mpu.accelY();
  aZ = mpu.accelZ();

  gX = mpu.gyroX();
  gY = mpu.gyroY();
  gZ = mpu.gyroZ();

  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  altitude = bmp.readAltitude(1031.25);

  Serial.print("AccelX: "); Serial.println(aX);
  Serial.print("AccelY: "); Serial.println(aY);
  Serial.print("AccelZ: "); Serial.println(aZ);

  Serial.println();

  Serial.print("GyroX: "); Serial.println(gX);
  Serial.print("GyroY: "); Serial.println(gY);
  Serial.print("GyroZ: "); Serial.println(gZ);

  Serial.println();

  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Pressure: "); Serial.println(pressure);
  Serial.print("Altitude: "); Serial.println(altitude);

  Serial.println();

  delay(1000);
}
