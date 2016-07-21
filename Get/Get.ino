void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  uint8_t buff;
  int cnt;

  union d{
    uint8_t data[9];
    struct{
      uint8_t allsw;
      uint16_t axis[4];
    };
  } twe;

  do{
    if (Serial1.available())
    {
      buff = Serial1.read();
      if (buff == 0x3a)
      {
        cnt = 0;
      }
      else
      {
        twe.data[cnt] = buff;
        if (cnt < 8)
        {
          cnt++;
        }
        else
        {
          break;
        }
      }
    }
  }while(1);
  Serial.println(twe.axis[1], HEX);
}
