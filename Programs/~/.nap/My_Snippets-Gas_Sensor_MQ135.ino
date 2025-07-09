#define ledPin 2
#define sensorAnalogPin 14

int sensorValueAnalog;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValueAnalog = analogRead(sensorAnalogPin);

  if(sensorValueAnalog > 570) {
      digitalWrite(ledPin, 1);
  }
  else {
    digitalWrite(ledPin, 0);
  }

  Serial.print("Analog Sensor Value : "); Serial.println(sensorValueAnalog, DEC);

  delay(1000);
}
