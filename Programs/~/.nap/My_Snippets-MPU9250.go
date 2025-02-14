#include <MPU9250_asukiaaa.h>
#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

MPU9250_asukiaaa mySensor;

float aX, aY, aZ, gX, gY, gZ;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);

  mySensor.beginAccel();
  mySensor.beginGyro();
}

void loop() {
  mySensor.accelUpdate();
  mySensor.gyroUpdate();

  aX = mySensor.accelX();
  aY = mySensor.accelY();
  aZ = mySensor.accelZ();

  gX = mySensor.gyroX();
  gY = mySensor.gyroY();
  gZ = mySensor.gyroZ();

  Serial.print("Accelerometer X : "); Serial.println(aX);
  Serial.print("Accelerometer Y : "); Serial.println(aY);
  Serial.print("Accelerometer Z : "); Serial.println(aZ);
  
  Serial.println();

  Serial.print("Gyrometer at X : "); Serial.println(gX);
  Serial.print("Gyrometer at Y : "); Serial.println(gY);
  Serial.print("Gyrometer at Z : "); Serial.println(gZ);
  
  Serial.println();

  delay(1000);
}
