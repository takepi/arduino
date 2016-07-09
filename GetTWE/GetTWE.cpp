#include "arduino.h"
#include "GetTWE.h"

Get_TWEData::Get_TWEData()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  twe.data[24] = {0};
}

void Get_TWEData::getdata()
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

unsigned char Get_TWEData::getid()
{
  getdata();
  return twe.id;
}
unsigned char Get_TWEData::getio()
{
  getdata();
  return twe.io;
}
unsigned char Get_TWEData::getappid()
{
  getdata();
  return twe.id;
}
unsigned char Get_TWEData::getprot()
{
  getdata();
  return twe.prot;
}
unsigned char Get_TWEData::getlqi()
{
  getdata();
  return twe.lqi;
}
unsigned long Get_TWEData::getno()
{
  getdata();
  return twe.lqi;
}
unsigned char Get_TWEData::getdevid()
{
  getdata();
  return twe.devid;
}
unsigned short Get_TWEData::getstmp()
{
  getdata();
  return twe.stmp;
}
unsigned char Get_TWEData::getrelay()
{
  getdata();
  return twe.relay;
}
unsigned short Get_TWEData::getvolt()
{
  getdata();
  return twe.volt;
}
unsigned char Get_TWEData::getdi()
{
  getdata();
  return twe.di & 0x0F;
}
unsigned char Get_TWEData::getdic()
{
  getdata();
  return twe.dic;
}
unsigned short Get_TWEData::getad()
{
  getdata();
  return (twe.ad4 << 12) | (twe.ad3 << 8) | (twe.ad2 << 4) | twe.ad1;
}
unsigned char Get_TWEData::getcorrad()
{
  getdata();
  return twe.corrad;
}
unsigned char Get_TWEData::getchsum()
{
  getdata();
  return twe.checksum;
}
