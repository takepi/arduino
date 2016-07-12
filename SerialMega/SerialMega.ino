#include <stdio.h>
 
static FILE uartout;

static int uart_putchar (char c, FILE *stream) {
    if (Serial.write(c) > 0) {
      return 0;
    } else {
      return -1;
    }
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
 
  int i = 10;
  char s[] = "abcd";
  printf("i = %d, s = %s\n", i, s);
}

void loop() {
  int cnt = 0;
  uint8_t buff;
  uint8_t allbtn;
  bool sw0;
  bool sw1;
  bool sw2;
  bool sw3;
  double xaxis0;
  double yaxis0;
  double xaxis1;
  double yaxis1;

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

  do {
    if (Serial1.available())
    {
      buff = uint8_t(Serial1.read());
      twe.data[cnt] = buff;
      cnt++;
    }
  } while (buff != '\n');

  xaxis0 = (twe.analog0 - 255) / 255.0;
  yaxis0 = (twe.analog1 - 255) / 255.0;
  xaxis1 = (twe.analog2 - 255) / 255.0;
  yaxis1 = (twe.analog3 - 255) / 255.0;
}
