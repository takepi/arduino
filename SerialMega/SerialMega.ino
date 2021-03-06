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
  Serial.begin(115200);
  Serial1.begin(115200);
  
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
}

void loop() {
  int cnt = 0;
  char *ptr, buff;
  bool flg = true;

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
      if (buff != '\n')
      {
        twe.data[cnt] = buff;
        cnt++;
      }
      /*if (buff != '\n')
      {
        if (flg)
        {
          twe.data[cnt] = strtol(&buff, &ptr, 16) << 3;
          flg = false;
        }
        else if (!flg)
        {
          twe.data[cnt] |= strtol(&buff, &ptr, 16);
          flg = true;
          cnt++;
        }
      }*/
    }
  } while (buff != '\n');
  Serial.println();

  Serial.print("btn : ");
  Serial.println(cnt);
}
