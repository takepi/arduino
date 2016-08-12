void setup() {
  Serial.begin(115200);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  uint8_t i;
  uint8_t allsw = 0;
  bool sw;

  for (i = 0; i <= 7; i++)
  {
    allsw |= digitalRead(i+2) << i;
  }

  Serial.write(':');
  Serial.write(~allsw);

  delay(10);
}
