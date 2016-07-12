void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  int cnt = 0;
  uint8_t buff;

  do {
    if (Serial1.available())
    {
      buff = char(Serial1.read());
      if (buff != '\n')
      {
        Serial.print(buff);
      }
      else
      {
        Serial.println();
      }
    }
  } while (buff != '\n');
}
