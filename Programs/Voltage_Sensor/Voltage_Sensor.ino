#define VOLTAGE_PIN 14
#define REF_VOLTAGE 3.3
#define ADC_RESOLUTION 4095


void setup() {
  Serial.begin(115200);
  pinMode(VOLTAGE_PIN, INPUT);
}

void loop() {
  int adcVal = analogRead(VOLTAGE_PIN);
  float voltage = (adcVal/(float)ADC_RESOLUTION) * REF_VOLTAGE;
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.println();
  delay(1000);
}
