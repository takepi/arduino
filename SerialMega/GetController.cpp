#include <arduino.h>
#include "GetController.h"

GetController::GetController()
{
  Serial1.begin(9600);
}

void GetController::getdata()
{
  int cnt;
  uint8_t buff;
  do {
    if (Serial1.available())
    {
      buff = uint8_t(Serial1.read());
      twe.data[cnt] = buff;
      cnt++;
    }
  } while (buff != '\n');
}

uint8_t GetController::getallsw()
{
  getdata();
  return twe.allsw;
}

bool GetController::getsw(int num)
{
  getdata();
  return twe.allsw & int(pow(2, num));
}

void GetController::getallai(double ais[4])
{
  getdata();
  ais[0] = (twe.analog0 - 255) / 255.0;
  ais[1] = (twe.analog1 - 255) / 255.0;
  ais[2] = (twe.analog2 - 255) / 255.0;
  ais[3] = (twe.analog3 - 255) / 255.0;
}

double GetController::getai(int num)
{
  getdata();
  switch (num){
    case 0 : return (twe.analog0 - 255) / 255.0; break;
    case 1 : return (twe.analog1 - 255) / 255.0; break;
    case 2 : return (twe.analog2 - 255) / 255.0; break;
    case 3 : return (twe.analog3 - 255) / 255.0; break;
  }
}

