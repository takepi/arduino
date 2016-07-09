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
      if (a != ':' && a != '\n')
      {
        if (flg)
        {
          data[cnt] = strtol(&a, &ptr, 16) << 4;
          flg = false;
        }
        else if (!flg)
        {
          data[cnt] |= strtol(&a, &ptr, 16);
          flg = true;
          Serial.print(data[cnt], HEX);
          Serial.print("|");
          cnt++;
        }
      }
      if (a == ':')
      {
        Serial.println();
        Serial.print("cnt_");
        Serial.println(cnt);
        cnt = 0;
        flg = true;
      }
    }
  }
}
