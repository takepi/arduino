void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  pinMode(52, OUTPUT);
}

void loop() {
  char buff;
  Serial2.println("a");
  if (Serial1.available())
  {
    digitalWrite(52, HIGH);
    buff = Serial1.read();
    Serial.println(buff);
  }
  digitalWrite(52, LOW);
}
