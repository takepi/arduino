#ifndef GETCONTROLLER_H
#define GETCONTROLLER_H

class GetCon
{
  public:
    GetCon();
    uint8_t GetAllSW();
    bool GetSW(int num);
    double Get0X();
    double Get0Y();
    double Get1X();
    double Get1Y();
    bool GetError();
  private:
    void GetData();
    double GetAxis(int num);
    union d{
      uint8_t data[10];
      struct{
        uint8_t allsw;
        uint16_t axis[4];
        bool errorflg;
      };
    } twe;
};

#endif
