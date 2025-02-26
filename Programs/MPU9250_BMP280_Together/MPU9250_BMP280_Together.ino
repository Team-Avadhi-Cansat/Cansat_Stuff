#include <Wire.h>
#include <SPI.h>
#include <MPU9250_asukiaaa.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define CSB 10


MPU9250_asukiaaa mpu;
Adafruit_BMP280 bmp(CSB);

float aX, aY, aZ, aSqrt, gX, gY, gZ, mX, mY, mZ, mDirection;
float temperature, pressure, altitude;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  while(!Serial);

  mpu.beginAccel();
  mpu.beginGyro();
  mpu.beginMag();

  while(!bmp.begin()) {
      Serial.println("BMP280 not found");
      while(1);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, 
                  Adafruit_BMP280::SAMPLING_X2, 
                  Adafruit_BMP280::SAMPLING_X16, 
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);

}

void loop() {
  mpu.accelUpdate();
  mpu.gyroUpdate();
  mpu.magUpdate();

  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  altitude = bmp.readAltitude(1031.25); 

  aX = mpu.accelX();
  aY = mpu.accelY();
  aZ = mpu.accelZ();
  aSqrt = mpu.accelSqrt();

  gX = mpu.gyroX();
  gY = mpu.gyroY();
  gZ = mpu.gyroZ();

  mX = mpu.magX();
  mY = mpu.magY();
  mZ = mpu.magZ();
  mDirection = mpu.magHorizDirection();

  Serial.println("\nBMP280 DATA");
  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Pressure: "); Serial.println(pressure);
  Serial.print("Altitude: "); Serial.println(altitude);

  Serial.println("\nMPU9250 DATA");
  Serial.println("Accelerometer: "); 
  Serial.print("X: "); Serial.println(aX);
  Serial.print("Y: "); Serial.println(aY);
  Serial.print("Z: "); Serial.println(aZ);
  Serial.print("Sqrt: "); Serial.println(aSqrt);

  Serial.println("\nGyrometer: ");
  Serial.print("X: "); Serial.println(gX);
  Serial.print("Y: "); Serial.println(gY);
  Serial.print("Z: "); Serial.println(gZ);

  Serial.println("\nMagnetometer: ");

  Serial.print("X: "); Serial.println(mZ);
  Serial.print("Y: "); Serial.println(mY);
  Serial.print("Z: "); Serial.println(mZ);
  Serial.print("Horizontal Direction: "); Serial.println(mDirection);

  delay(1000);
}
