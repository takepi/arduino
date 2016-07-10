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

class TWEPacket {
  public:
    TWEPacket(union d gdata);
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
    union d twe;
};

TWEPacket::TWEPacket(union d gdata)
{
  twe = gdata;
}

unsigned char TWEPacket::getid()
{
  return twe.id;
}
unsigned char TWEPacket::getio()
{
  return twe.io;
}
unsigned char TWEPacket::getappid()
{
  return twe.id;
}
unsigned char TWEPacket::getprot()
{
  return twe.prot;
}
unsigned char TWEPacket::getlqi()
{
  return twe.lqi;
}
unsigned long TWEPacket::getno()
{
  return twe.lqi;
}
unsigned char TWEPacket::getdevid()
{
  return twe.devid;
}
unsigned short TWEPacket::getstmp()
{
  return twe.stmp;
}
unsigned char TWEPacket::getrelay()
{
  return twe.relay;
}
unsigned short TWEPacket::getvolt()
{
  return twe.volt;
}
unsigned char TWEPacket::getdi()
{
  return twe.di & 0x0F;
}
unsigned char TWEPacket::getdic()
{
  return twe.dic;
}
unsigned long TWEPacket::getad()
{
  return twe.ad;
}
unsigned char TWEPacket::getcorrad()
{
  return twe.corrad;
}
unsigned char TWEPacket::getchsum()
{
  return twe.checksum;
}

class Get_TWEData {
  public:
    Get_TWEData();
    void getdata(TWEPacket *pclassp);
};

Get_TWEData::Get_TWEData()
{
  Serial1.begin(115200);
}

void Get_TWEData::getdata(TWEPacket *pclassp)
{
  union d twe;
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

  pclassp = new TWEPacket(twe);
}

void loop() {
  Get_TWEData gtwe;
  TWEPacket *pt;
  while (1)
  {
    gtwe.getdata(pt);
    Serial.println(pt->getad(), HEX);
    delete pt;
  }
}
