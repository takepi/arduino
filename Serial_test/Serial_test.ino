void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  union d {
    unsigned char data[24] = {0};
    struct {
      unsigned char id;
      unsigned char io;
      unsigned char appid;
      unsigned char prot;
      unsigned char lqi;
      unsigned long no;
      unsigned char devid;
      unsigned short stmp;
      unsigned char relay;
      unsigned short volt;
      unsigned char empty;
      unsigned char di;
      unsigned char dic;
      unsigned char ad1;
      unsigned char ad2;
      unsigned char ad3;
      unsigned char ad4;
      unsigned char corrad;
      unsigned char checksum;
    };
  };

  int cnt, i = 0;
  char a, *ptr;
  long b;
  bool di1, di2, di3, di4, flg = true;
  union d twe;

  while (1)
  {
    cnt = 0;
    do {
      if (Serial1.available())
      {
        a = char(Serial1.read());
        if (a != ':' && a != '\n')
        {
          if (flg)
          {
            twe.data[cnt] = strtol(&a, &ptr, 16) << 4;
            flg = false;
          }
          else if (!flg)
          {
            twe.data[cnt] |= strtol(&a, &ptr, 16);
            flg = true;
            cnt++;
          }
        }
      }
    } while (a != ':');
    flg = true;

    //Serial.print("AD1 : ");Serial.println(twe.ad1, HEX);

    twe.di &= 0x0F;
    Serial.println(twe.di, BIN);
    di1 = twe.di & 0x01;
    di2 = twe.di & 0x02;
    di3 = twe.di & 0x04;
    di4 = twe.di & 0x08;
    
    Serial.print("DI1 : "); Serial.println(di1);
    Serial.print("DI2 : "); Serial.println(di2);
    Serial.print("DI3 : "); Serial.println(di3);
    Serial.print("DI4 : "); Serial.println(di4);
  }
}
