void setup() {
  Serial.begin(115200);
}

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
    unsigned long ad;
    unsigned char corrad;
    unsigned char checksum;
  };
};

class Get_TWEData {
  public:
    Get_TWEData();
    void getdata(int*);/
};

Get_TWEData::GetTWEData()
{
  Serial1.begin(115200);
}

class TWEPacket {
  public:
    union d twe;

    TWEPacket();
    unsigned char getid();
    unsigned char getio();
    unsigned char getappid();
    unsigned char getprot();
    unsigned char getlqi();
    unsigned long getno();
    unsigned char getdevid();
    unsigned short getstmp();
    unsigned char getrelay();
    unsigned short getvolt();
    unsigned char getdi();
    unsigned char getdic();
    unsigned long getad();
    unsigned char getcorrad();
    unsigned char getchsum();

  private:
    void getdata();
};

TWEPacket::TWEPacket()
{
  Serial1.begin(115200);
  twe.data[24] = {0};
}

void TWEPacket::getdata()
{
  bool flg = true;
  char buff, *ptr;
  int cnt = 0;

  do {
    if (Serial1.available())
    {
      buff = char(Serial1.read());
      if (buff != ';' && buff != '\n')
      {
        if (flg)
        {
          twe.data[cnt] = strtol(&buff, &ptr, 16) << 4;
          flg = false;
        }
        else if (!flg)
        {
          twe.data[cnt] |= strtol(&buff, &ptr, 16);
          flg = true;
          cnt++;
        }
      }
    }
  } while (buff != ':');
}

unsigned char TWEPacket::getid()
{
  getdata();
  return twe.id;
}
unsigned char TWEPacket::getio()
{
  getdata();
  return twe.io;
}
unsigned char TWEPacket::getappid()
{
  getdata();
  return twe.id;
}
unsigned char TWEPacket::getprot()
{
  getdata();
  return twe.prot;
}
unsigned char TWEPacket::getlqi()
{
  getdata();
  return twe.lqi;
}
unsigned long TWEPacket::getno()
{
  getdata();
  return twe.lqi;
}
unsigned char TWEPacket::getdevid()
{
  getdata();
  return twe.devid;
}
unsigned short TWEPacket::getstmp()
{
  getdata();
  return twe.stmp;
}
unsigned char TWEPacket::getrelay()
{
  getdata();
  return twe.relay;
}
unsigned short TWEPacket::getvolt()
{
  getdata();
  return twe.volt;
}
unsigned char TWEPacket::getdi()
{
  getdata();
  return twe.di & 0x0F;
}
unsigned char TWEPacket::getdic()
{
  getdata();
  return twe.dic;
}
unsigned long TWEPacket::getad()
{
  getdata();
  return twe.ad;
}
unsigned char TWEPacket::getcorrad()
{
  getdata();
  return twe.corrad;
}
unsigned char TWEPacket::getchsum()
{
  getdata();
  return twe.checksum;
}

void loop() {
  TWEPacket data;
  while (1)
  {
    Serial.println(data.getad(), HEX);
  }
}
