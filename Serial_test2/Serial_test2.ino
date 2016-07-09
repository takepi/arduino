void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  char a , *ptr;
  long b;
  int cnt;
  unsigned char data[48];
  bool flg = true;

  while (1)
  {
    if (Serial1.available())
    {
      a = char(Serial1.read());
      //Serial.print(a);
      if (a != ':' && a != '\n')
      {
        data[cnt] = strtol(&a, &ptr, 16);
        Serial.print(data[cnt], HEX);
        cnt++;
      }
      if (a == '\n')
      {
        Serial.println();
        Serial.print("cnt_");
        Serial.println(cnt);
        cnt = 0;
      }
    }
  }
}
