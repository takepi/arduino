void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

union d{
    uint8_t data[9];
    struct{
      uint8_t allsw;
      uint16_t axis[4];
    };
  } twe;

void loop()
{
  for (int i = 0; i < 9; i++)
  {
    Serial.print(twe.data[i], HEX);
  }
  Serial.println();
}

void serialEvent() {
  uint8_t buff;
  int cnt;

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
}
