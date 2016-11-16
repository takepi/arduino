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
  Serial.begin(19200);

  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
}

void loop() {
  uint8_t allsw = 0xDD;
  uint16_t analog0 = 0x00ff;
  uint16_t analog1 = 0x03ff;
  uint16_t analog2 = 0x03ff;
  uint16_t analog3 = 0x03ff;
  
  Serial.print("TXDA ");

  printf("%02x", allsw);
  printf("%04x", analog0);
  printf("%04x", analog1);
  printf("%04x", analog2);
  printf("%04x", analog3);

  Serial.print("\r\n");
  
  //delay(10);
}
