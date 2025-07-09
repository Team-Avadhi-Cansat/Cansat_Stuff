void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, 1);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(13, 0);
  Serial.println("LED OFF");
  delay(2000);
}
