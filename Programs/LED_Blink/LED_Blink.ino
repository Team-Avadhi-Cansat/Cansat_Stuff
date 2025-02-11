#define ledPin 2

int ledState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  digitalWrite(ledPin, !ledState);
  ledState = !ledState;
  delay(1000);
}
