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
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
}

void loop() {
  uint8_t i;
  uint8_t allsw = 0;
  uint16_t analog0;
  uint16_t analog1;
  uint16_t analog2;
  uint16_t analog3;
  
  analog0 = analogRead(A0);
  analog1 = analogRead(A1);
  analog2 = analogRead(A2);
  analog3 = analogRead(A3);

  if (analog0 < 0) analog0 = 0;
  else if (analog0 == 0x3a) analog0 = 0x39;
  else if (analog0 > 0x3ff) analog0 = 0x3ff;
  if (analog1 < 0) analog1 = 0;
  else if (analog1 == 0x3a) analog1 = 0x39;
  else if (analog1 > 0x3ff) analog1 = 0x3ff;
  if (analog2 < 0) analog2 = 0;
  else if (analog2 == 0x3a) analog2 = 0x39;
  else if (analog2 > 0x3ff) analog2 = 0x3ff;
  if (analog3 < 0) analog3 = 0;
  else if (analog3 == 0x3a) analog3 = 0x39;
  else if (analog3 > 0x3ff) analog3 = 0x3ff;
  
  allsw |= digitalRead(9) << 7;
  allsw |= digitalRead(7) << 6;
  allsw |= digitalRead(4) << 5;
  allsw |= digitalRead(5) << 4;
  allsw |= digitalRead(3) << 3;
  allsw |= digitalRead(2) << 2;
  allsw |= digitalRead(6) << 1;
  allsw |= digitalRead(8) << 0;

  Serial.write(':');
  Serial.write(~allsw);
  Serial.write(analog0 >> 8);
  Serial.write(analog0 & 0xff);
  Serial.write(analog1>> 8);
  Serial.write(analog1 & 0xff);
  Serial.write(analog2 >> 8);
  Serial.write(analog2 & 0xff);
  Serial.write(analog3 >> 8);
  Serial.write(analog3 & 0xff);

  delay(10);
}
