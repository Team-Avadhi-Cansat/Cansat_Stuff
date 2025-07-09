#define GAS_PIN 24
#define ledPin 13 

int gas_val;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  gas_val = analogRead(GAS_PIN);

  if(gas_val > 570) {
    digitalWrite(ledPin, 1);
  } 
  else {
    digitalWrite(ledPin, 0);
  }
  Serial.print("Gas Sensor: "); Serial.println(gas_val, DEC);

  delay(1000);
}
