void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(A1);
  Serial.println(sensorValue);
  delay(1);
}
