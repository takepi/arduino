#include <arduino.h>
#include "GetController.h"

GetCon::GetCon()
{
  Serial.begin(115200);
}

void GetCon::GetData()
{
  uint8_t buff;
  int cnt;
  int errcnt = 0;

  do{
    if (Serial.available())
    {
      buff = Serial.read();
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
          twe.errorflg = false;
          break;
        }
      }
    }
    else
    {
      errcnt++;
    }
    if (errcnt > 100)
    {
      twe.errorflg = true;
      break;
    }
  }while(1);
}

uint8_t GetCon::GetAllSW()
{
  GetData();
  return twe.allsw;
}

bool GetCon::GetSW(int num)
{
  GetData();
  return (bool)(twe.allsw & (int)(pow(2.0, (double)num)));
}

double GetCon::GetAxis(int num)
{
  GetData();
  double axis;
  axis = (double)(twe.axis[num] - 511) / 511.0;
  if (axis > -0.01 && axis < 0.01)
  {
    axis = 0;
  }
  else if (axis < -1)
  {
    axis = -1;
  }
  else if (axis > 1)
  {
    axis = 1;
  }

  return axis;
}

double GetCon::Get0X()
{
  GetData();
  return GetAxis(0);
}

double GetCon::Get0Y()
{
  GetData();
  return GetAxis(1);
}

double GetCon::Get1X()
{
  GetData();
  return GetAxis(2);
}

double GetCon::Get1Y()
{
  GetData();
  return GetAxis(3);
}

bool GetCon::GetError()
{
  GetData();
  return twe.errorflg;
}

