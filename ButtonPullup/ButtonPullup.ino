void setup() {
  Serial.begin(115200);
  pinMode(52, INPUT_PULLUP);
  pinMode(50, OUTPUT);
}

void loop() {
  digitalWrite(50, HIGH);
  delay(1000);
  Serial.println(digitalRead(52));
  digitalWrite(50, LOW);
  delay(1000);
  Serial.println(digitalRead(52));
}
