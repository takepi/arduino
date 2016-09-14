#ifndef GETCONTROLLER_H
#define GETCONTROLLER_H

class GetController{
  public:
    GetController();
    uint8_t getallsw();
    bool getsw(int num);
    void getallai(double ais[4]);
    double getai(int num);

  private:
    union d {
    uint8_t data[9] = {0};
    struct {
      uint8_t allsw;
      uint16_t analog0;
      uint16_t analog1;
      uint16_t analog2;
      uint16_t analog3;
    };
  } twe;
  void getdata();
};
#endif
