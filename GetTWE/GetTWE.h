#include "arduino.h"
#ifndef GetTWE_h
#define GetTWE_h

class Get_TWEData{
  public:
    Get_TWEData();
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
    unsigned short getad();
    unsigned char getcorrad();
    unsigned char getchsum();

  private:
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
    } twe;
    void getdata();
};

#endif
